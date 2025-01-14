#include "CDAccessoryDefaultLocTable.h"
//Generated by xmlDb2dDatabaseGenerator on 2022-03-04 00:23:32.841621
//DO NOT EDIT THIS FILE MANUALLY!

CDAccessoryDefaultLocTable::CDAccessoryDefaultLocTable() {
	unsigned int size = 0;
	auto tableSize = CDClientDatabase::ExecuteQuery("SELECT COUNT(*) FROM AccessoryDefaultLoc");
		while (!tableSize.eof()) {
		size = tableSize.getIntField(0, 0);
		tableSize.nextRow();
	}

	tableSize.finalize();
	this->m_entries.reserve(size);

	auto tableData = CDClientDatabase::ExecuteQuery("SELECT * FROM AccessoryDefaultLoc");
	while (!tableData.eof()) {
		CDAccessoryDefaultLoc entry;
		entry.GroupID = tableData.getIntField(0, int{});
		entry.Description = tableData.getStringField(1, std::string{}.c_str());
		entry.Pos_X = tableData.getFloatField(2, float{});
		entry.Pos_Y = tableData.getFloatField(3, float{});
		entry.Pos_Z = tableData.getFloatField(4, float{});
		entry.Rot_X = tableData.getFloatField(5, float{});
		entry.Rot_Y = tableData.getFloatField(6, float{});
		entry.Rot_Z = tableData.getFloatField(7, float{});
		this->m_entries.push_back(entry);
		tableData.nextRow();
	}

	tableData.finalize();
}

CDAccessoryDefaultLocTable::~CDAccessoryDefaultLocTable() {
}

std::string CDAccessoryDefaultLocTable::GetName(void) const {
	return "AccessoryDefaultLoc";
}

std::vector<CDAccessoryDefaultLoc> CDAccessoryDefaultLocTable::Query(std::function<bool(CDAccessoryDefaultLoc)> predicate) {
	std::vector<CDAccessoryDefaultLoc> data = cpplinq::from(this->m_entries)
		>> cpplinq::where(predicate)
		>> cpplinq::to_vector();

	return data;
}

std::vector<CDAccessoryDefaultLoc> CDAccessoryDefaultLocTable::GetEntries(void) const {
	return this->m_entries;
}
