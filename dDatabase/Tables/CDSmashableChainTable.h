#pragma once
#include "CDTable.h"

//Generated by xmlDb2dDatabaseGenerator on 2022-03-04 00:23:33.415849
//DO NOT EDIT THIS FILE MANUALLY!

struct CDSmashableChain {
	int chainIndex;
	int chainLevel;
	int lootMatrixID;
	int rarityTableIndex;
	int currencyIndex;
	int currencyLevel;
	int smashCount;
	int timeLimit;
	int chainStepID;
};

class CDSmashableChainTable : public CDTable {
private:
	std::vector<CDSmashableChain> m_entries;
public:
	CDSmashableChainTable();
	~CDSmashableChainTable();
	std::string GetName(void) const override;

std::vector<CDSmashableChain> Query(std::function<bool(CDSmashableChain)> predicate);
	std::vector<CDSmashableChain> GetEntries(void) const;
};