#include "CDSmashableChainIndexTable.h"
//Generated by xmlDb2dDatabaseGenerator on 2022-03-04 00:23:33.421700
//DO NOT EDIT THIS FILE MANUALLY!

CDSmashableChainIndexTable::CDSmashableChainIndexTable() {
	unsigned int size = 0;
	auto tableSize = CDClientDatabase::ExecuteQuery("SELECT COUNT(*) FROM SmashableChainIndex");
		while (!tableSize.eof()) {
		size = tableSize.getIntField(0, 0);
		tableSize.nextRow();
	}

	tableSize.finalize();
	this->m_entries.reserve(size);

	auto tableData = CDClientDatabase::ExecuteQuery("SELECT * FROM SmashableChainIndex");
	while (!tableData.eof()) {
		CDSmashableChainIndex entry;
		entry.id = tableData.getIntField(0, int{});
		entry.targetGroup = tableData.getStringField(1, std::string{}.c_str());
		entry.description = tableData.getStringField(2, std::string{}.c_str());
		entry.continuous = tableData.getIntField(3, int{});
		this->m_entries.push_back(entry);
		tableData.nextRow();
	}

	tableData.finalize();
}

CDSmashableChainIndexTable::~CDSmashableChainIndexTable() {
}

std::string CDSmashableChainIndexTable::GetName(void) const {
	return "SmashableChainIndex";
}

std::vector<CDSmashableChainIndex> CDSmashableChainIndexTable::Query(std::function<bool(CDSmashableChainIndex)> predicate) {
	std::vector<CDSmashableChainIndex> data = cpplinq::from(this->m_entries)
		>> cpplinq::where(predicate)
		>> cpplinq::to_vector();

	return data;
}

std::vector<CDSmashableChainIndex> CDSmashableChainIndexTable::GetEntries(void) const {
	return this->m_entries;
}
