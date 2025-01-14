#include "CDFootstepsTable.h"
//Generated by xmlDb2dDatabaseGenerator on 2022-03-04 00:23:32.988857
//DO NOT EDIT THIS FILE MANUALLY!

CDFootstepsTable::CDFootstepsTable() {
	unsigned int size = 0;
	auto tableSize = CDClientDatabase::ExecuteQuery("SELECT COUNT(*) FROM Footsteps");
		while (!tableSize.eof()) {
		size = tableSize.getIntField(0, 0);
		tableSize.nextRow();
	}

	tableSize.finalize();
	this->m_entries.reserve(size);

	auto tableData = CDClientDatabase::ExecuteQuery("SELECT * FROM Footsteps");
	while (!tableData.eof()) {
		CDFootsteps entry;
		entry.objectType = tableData.getStringField(0, std::string{}.c_str());
		entry.stone = tableData.getStringField(1, std::string{}.c_str());
		entry.grass = tableData.getStringField(2, std::string{}.c_str());
		entry.wood = tableData.getStringField(3, std::string{}.c_str());
		entry.plastic = tableData.getStringField(4, std::string{}.c_str());
		entry.gravel = tableData.getStringField(5, std::string{}.c_str());
		entry.mud = tableData.getStringField(6, std::string{}.c_str());
		this->m_entries.push_back(entry);
		tableData.nextRow();
	}

	tableData.finalize();
}

CDFootstepsTable::~CDFootstepsTable() {
}

std::string CDFootstepsTable::GetName(void) const {
	return "Footsteps";
}

std::vector<CDFootsteps> CDFootstepsTable::Query(std::function<bool(CDFootsteps)> predicate) {
	std::vector<CDFootsteps> data = cpplinq::from(this->m_entries)
		>> cpplinq::where(predicate)
		>> cpplinq::to_vector();

	return data;
}

std::vector<CDFootsteps> CDFootstepsTable::GetEntries(void) const {
	return this->m_entries;
}
