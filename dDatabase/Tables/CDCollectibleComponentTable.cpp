#include "CDCollectibleComponentTable.h"
//Generated by xmlDb2dDatabaseGenerator on 2022-03-04 00:23:32.920051
//DO NOT EDIT THIS FILE MANUALLY!

CDCollectibleComponentTable::CDCollectibleComponentTable() {
	unsigned int size = 0;
	auto tableSize = CDClientDatabase::ExecuteQuery("SELECT COUNT(*) FROM CollectibleComponent");
		while (!tableSize.eof()) {
		size = tableSize.getIntField(0, 0);
		tableSize.nextRow();
	}

	tableSize.finalize();
	this->m_entries.reserve(size);

	auto tableData = CDClientDatabase::ExecuteQuery("SELECT * FROM CollectibleComponent");
	while (!tableData.eof()) {
		CDCollectibleComponent entry;
		entry.id = tableData.getIntField(0, int{});
		entry.requirement_mission = tableData.getIntField(1, int{});
		this->m_entries.push_back(entry);
		tableData.nextRow();
	}

	tableData.finalize();
}

CDCollectibleComponentTable::~CDCollectibleComponentTable() {
}

std::string CDCollectibleComponentTable::GetName(void) const {
	return "CollectibleComponent";
}

std::vector<CDCollectibleComponent> CDCollectibleComponentTable::Query(std::function<bool(CDCollectibleComponent)> predicate) {
	std::vector<CDCollectibleComponent> data = cpplinq::from(this->m_entries)
		>> cpplinq::where(predicate)
		>> cpplinq::to_vector();

	return data;
}

std::vector<CDCollectibleComponent> CDCollectibleComponentTable::GetEntries(void) const {
	return this->m_entries;
}