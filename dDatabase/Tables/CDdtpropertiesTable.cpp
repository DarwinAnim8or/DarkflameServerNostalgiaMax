#include "CDdtpropertiesTable.h"
//Generated by xmlDb2dDatabaseGenerator on 2022-03-04 00:23:32.965918
//DO NOT EDIT THIS FILE MANUALLY!

CDdtpropertiesTable::CDdtpropertiesTable() {
	unsigned int size = 0;
	auto tableSize = CDClientDatabase::ExecuteQuery("SELECT COUNT(*) FROM dtproperties");
		while (!tableSize.eof()) {
		size = tableSize.getIntField(0, 0);
		tableSize.nextRow();
	}

	tableSize.finalize();
	this->m_entries.reserve(size);

	auto tableData = CDClientDatabase::ExecuteQuery("SELECT * FROM dtproperties");
	while (!tableData.eof()) {
		CDdtproperties entry;
		entry.id = tableData.getIntField(0, int{});
		entry.objectid = tableData.getIntField(1, int{});
		entry.property = tableData.getStringField(2, std::string{}.c_str());
		entry.value = tableData.getStringField(3, std::string{}.c_str());
		entry.uvalue = tableData.getStringField(4, std::string{}.c_str());
		//entry.lvalue = tableData.getimageField(5, image{}); //what?
		entry.version = tableData.getIntField(6, int{});
		this->m_entries.push_back(entry);
		tableData.nextRow();
	}

	tableData.finalize();
}

CDdtpropertiesTable::~CDdtpropertiesTable() {
}

std::string CDdtpropertiesTable::GetName(void) const {
	return "dtproperties";
}

std::vector<CDdtproperties> CDdtpropertiesTable::Query(std::function<bool(CDdtproperties)> predicate) {
	std::vector<CDdtproperties> data = cpplinq::from(this->m_entries)
		>> cpplinq::where(predicate)
		>> cpplinq::to_vector();

	return data;
}

std::vector<CDdtproperties> CDdtpropertiesTable::GetEntries(void) const {
	return this->m_entries;
}