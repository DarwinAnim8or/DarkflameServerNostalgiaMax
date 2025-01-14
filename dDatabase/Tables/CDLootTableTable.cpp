#include "CDLootTableTable.h"
//Generated by xmlDb2dDatabaseGenerator on 2022-03-04 00:23:33.123497
//DO NOT EDIT THIS FILE MANUALLY!

CDLootTableTable::CDLootTableTable() {
	unsigned int size = 0;
	auto tableSize = CDClientDatabase::ExecuteQuery("SELECT COUNT(*) FROM LootTable");
		while (!tableSize.eof()) {
		size = tableSize.getIntField(0, 0);
		tableSize.nextRow();
	}

	tableSize.finalize();
	this->m_entries.reserve(size);

	auto tableData = CDClientDatabase::ExecuteQuery("SELECT * FROM LootTable");
	while (!tableData.eof()) {
		CDLootTable entry;
		entry.itemid = tableData.getIntField(0, int{});
		entry.LootTableIndex = tableData.getIntField(1, int{});
		entry.id = tableData.getIntField(2, int{});
		entry.MissionDrop = tableData.getIntField(3, bool{});
		this->m_entries.push_back(entry);
		tableData.nextRow();
	}

	tableData.finalize();
}

CDLootTableTable::~CDLootTableTable() {
}

std::string CDLootTableTable::GetName(void) const {
	return "LootTable";
}

std::vector<CDLootTable> CDLootTableTable::Query(std::function<bool(CDLootTable)> predicate) {
	std::vector<CDLootTable> data = cpplinq::from(this->m_entries)
		>> cpplinq::where(predicate)
		>> cpplinq::to_vector();

	return data;
}

std::vector<CDLootTable> CDLootTableTable::GetEntries(void) const {
	return this->m_entries;
}
