#pragma once
#include "CDTable.h"

//Generated by xmlDb2dDatabaseGenerator on 2022-03-04 00:23:33.419707
//DO NOT EDIT THIS FILE MANUALLY!

struct CDSmashableChainIndex {
	int id;
	std::string targetGroup;
	std::string description;
	int continuous;
};

class CDSmashableChainIndexTable : public CDTable {
private:
	std::vector<CDSmashableChainIndex> m_entries;
public:
	CDSmashableChainIndexTable();
	~CDSmashableChainIndexTable();
	std::string GetName(void) const override;

std::vector<CDSmashableChainIndex> Query(std::function<bool(CDSmashableChainIndex)> predicate);
	std::vector<CDSmashableChainIndex> GetEntries(void) const;
};