#include "CDmapComponentTypeTable.h"
//Generated by xmlDb2dDatabaseGenerator on 2022-03-04 00:23:33.151422
//DO NOT EDIT THIS FILE MANUALLY!

CDmapComponentTypeTable::CDmapComponentTypeTable() {
	unsigned int size = 0;
	auto tableSize = CDClientDatabase::ExecuteQuery("SELECT COUNT(*) FROM mapComponentType");
		while (!tableSize.eof()) {
		size = tableSize.getIntField(0, 0);
		tableSize.nextRow();
	}

	tableSize.finalize();
	this->m_entries.reserve(size);

	auto tableData = CDClientDatabase::ExecuteQuery("SELECT * FROM mapComponentType");
	while (!tableData.eof()) {
		CDmapComponentType entry;
		entry.id = tableData.getIntField(0, int{});
		entry.label = tableData.getStringField(1, std::string{}.c_str());
		entry.table = tableData.getStringField(2, std::string{}.c_str());
		this->m_entries.push_back(entry);
		tableData.nextRow();
	}

	tableData.finalize();
}

CDmapComponentTypeTable::~CDmapComponentTypeTable() {
}

std::string CDmapComponentTypeTable::GetName(void) const {
	return "mapComponentType";
}

std::vector<CDmapComponentType> CDmapComponentTypeTable::Query(std::function<bool(CDmapComponentType)> predicate) {
	std::vector<CDmapComponentType> data = cpplinq::from(this->m_entries)
		>> cpplinq::where(predicate)
		>> cpplinq::to_vector();

	return data;
}

std::vector<CDmapComponentType> CDmapComponentTypeTable::GetEntries(void) const {
	return this->m_entries;
}