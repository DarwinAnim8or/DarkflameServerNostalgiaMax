#pragma once
#include "CDTable.h"

//Generated by xmlDb2dDatabaseGenerator on 2022-03-04 00:23:32.864733
//DO NOT EDIT THIS FILE MANUALLY!

struct CDAnimationIndex {
	int animationGroupID;
	std::string description;
	std::string groupType;
};

class CDAnimationIndexTable : public CDTable {
private:
	std::vector<CDAnimationIndex> m_entries;
public:
	CDAnimationIndexTable();
	~CDAnimationIndexTable();
	std::string GetName(void) const override;

std::vector<CDAnimationIndex> Query(std::function<bool(CDAnimationIndex)> predicate);
	std::vector<CDAnimationIndex> GetEntries(void) const;
};