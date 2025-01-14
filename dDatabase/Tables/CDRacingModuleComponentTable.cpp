#include "CDRacingModuleComponentTable.h"
//Generated by xmlDb2dDatabaseGenerator on 2022-03-04 00:23:33.328966
//DO NOT EDIT THIS FILE MANUALLY!

CDRacingModuleComponentTable::CDRacingModuleComponentTable() {
	unsigned int size = 0;
	auto tableSize = CDClientDatabase::ExecuteQuery("SELECT COUNT(*) FROM RacingModuleComponent");
		while (!tableSize.eof()) {
		size = tableSize.getIntField(0, 0);
		tableSize.nextRow();
	}

	tableSize.finalize();
	this->m_entries.reserve(size);

	auto tableData = CDClientDatabase::ExecuteQuery("SELECT * FROM RacingModuleComponent");
	while (!tableData.eof()) {
		CDRacingModuleComponent entry;
		entry.id = tableData.getIntField(0, int{});
		entry.topSpeed = tableData.getFloatField(1, float{});
		entry.acceleration = tableData.getFloatField(2, float{});
		entry.handling = tableData.getFloatField(3, float{});
		entry.stability = tableData.getFloatField(4, float{});
		entry.imagination = tableData.getFloatField(5, float{});
		this->m_entries.push_back(entry);
		tableData.nextRow();
	}

	tableData.finalize();
}

CDRacingModuleComponentTable::~CDRacingModuleComponentTable() {
}

std::string CDRacingModuleComponentTable::GetName(void) const {
	return "RacingModuleComponent";
}

std::vector<CDRacingModuleComponent> CDRacingModuleComponentTable::Query(std::function<bool(CDRacingModuleComponent)> predicate) {
	std::vector<CDRacingModuleComponent> data = cpplinq::from(this->m_entries)
		>> cpplinq::where(predicate)
		>> cpplinq::to_vector();

	return data;
}

std::vector<CDRacingModuleComponent> CDRacingModuleComponentTable::GetEntries(void) const {
	return this->m_entries;
}
