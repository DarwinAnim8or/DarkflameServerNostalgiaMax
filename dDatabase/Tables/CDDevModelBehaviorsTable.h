#pragma once
#include "CDTable.h"

//Generated by xmlDb2dDatabaseGenerator on 2022-03-04 00:23:32.958937
//DO NOT EDIT THIS FILE MANUALLY!

struct CDDevModelBehaviors {
	int ModelID;
	int BehaviorID;
};

class CDDevModelBehaviorsTable : public CDTable {
private:
	std::vector<CDDevModelBehaviors> m_entries;
public:
	CDDevModelBehaviorsTable();
	~CDDevModelBehaviorsTable();
	std::string GetName(void) const override;

std::vector<CDDevModelBehaviors> Query(std::function<bool(CDDevModelBehaviors)> predicate);
	std::vector<CDDevModelBehaviors> GetEntries(void) const;
};