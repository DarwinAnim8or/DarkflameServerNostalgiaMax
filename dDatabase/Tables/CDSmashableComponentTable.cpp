#include "CDSmashableComponentTable.h"
//Generated by xmlDb2dDatabaseGenerator on 2022-03-04 00:23:33.426795
//DO NOT EDIT THIS FILE MANUALLY!

CDSmashableComponentTable::CDSmashableComponentTable() {
	unsigned int size = 0;
	auto tableSize = CDClientDatabase::ExecuteQuery("SELECT COUNT(*) FROM SmashableComponent");
		while (!tableSize.eof()) {
		size = tableSize.getIntField(0, 0);
		tableSize.nextRow();
	}

	tableSize.finalize();
	this->m_entries.reserve(size);

	auto tableData = CDClientDatabase::ExecuteQuery("SELECT * FROM SmashableComponent");
	while (!tableData.eof()) {
		CDSmashableComponent entry;
		entry.id = tableData.getIntField(0, int{});
		entry.LootMatrixIndex = tableData.getIntField(1, int{});
		this->m_entries.push_back(entry);
		tableData.nextRow();
	}

	tableData.finalize();
}

CDSmashableComponentTable::~CDSmashableComponentTable() {
}

std::string CDSmashableComponentTable::GetName(void) const {
	return "SmashableComponent";
}

std::vector<CDSmashableComponent> CDSmashableComponentTable::Query(std::function<bool(CDSmashableComponent)> predicate) {
	std::vector<CDSmashableComponent> data = cpplinq::from(this->m_entries)
		>> cpplinq::where(predicate)
		>> cpplinq::to_vector();

	return data;
}

std::vector<CDSmashableComponent> CDSmashableComponentTable::GetEntries(void) const {
	return this->m_entries;
}