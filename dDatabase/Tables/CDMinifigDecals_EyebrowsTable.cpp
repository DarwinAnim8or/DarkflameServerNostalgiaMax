#include "CDMinifigDecals_EyebrowsTable.h"
//Generated by xmlDb2dDatabaseGenerator on 2022-03-04 00:23:33.191375
//DO NOT EDIT THIS FILE MANUALLY!

CDMinifigDecals_EyebrowsTable::CDMinifigDecals_EyebrowsTable() {
	unsigned int size = 0;
	auto tableSize = CDClientDatabase::ExecuteQuery("SELECT COUNT(*) FROM MinifigDecals_Eyebrows");
		while (!tableSize.eof()) {
		size = tableSize.getIntField(0, 0);
		tableSize.nextRow();
	}

	tableSize.finalize();
	this->m_entries.reserve(size);

	auto tableData = CDClientDatabase::ExecuteQuery("SELECT * FROM MinifigDecals_Eyebrows");
	while (!tableData.eof()) {
		CDMinifigDecals_Eyebrows entry;
		entry.ID = tableData.getIntField(0, int{});
		entry.High_path = tableData.getStringField(1, std::string{}.c_str());
		entry.Low_path = tableData.getStringField(2, std::string{}.c_str());
		entry.CharacterCreateValid = tableData.getIntField(3, bool{});
		entry.male = tableData.getIntField(4, bool{});
		entry.female = tableData.getIntField(5, bool{});
		this->m_entries.push_back(entry);
		tableData.nextRow();
	}

	tableData.finalize();
}

CDMinifigDecals_EyebrowsTable::~CDMinifigDecals_EyebrowsTable() {
}

std::string CDMinifigDecals_EyebrowsTable::GetName(void) const {
	return "MinifigDecals_Eyebrows";
}

std::vector<CDMinifigDecals_Eyebrows> CDMinifigDecals_EyebrowsTable::Query(std::function<bool(CDMinifigDecals_Eyebrows)> predicate) {
	std::vector<CDMinifigDecals_Eyebrows> data = cpplinq::from(this->m_entries)
		>> cpplinq::where(predicate)
		>> cpplinq::to_vector();

	return data;
}

std::vector<CDMinifigDecals_Eyebrows> CDMinifigDecals_EyebrowsTable::GetEntries(void) const {
	return this->m_entries;
}