#pragma once
#include "CDTable.h"

//Generated by xmlDb2dDatabaseGenerator on 2022-03-04 00:23:32.884137
//DO NOT EDIT THIS FILE MANUALLY!

struct CDBehaviorTemplate {
	int behaviorID;
	int templateID;
	int effectID;
	std::string effectHandle;
};

class CDBehaviorTemplateTable : public CDTable {
private:
	std::vector<CDBehaviorTemplate> m_entries;
public:
	CDBehaviorTemplateTable();
	~CDBehaviorTemplateTable();
	std::string GetName(void) const override;

std::vector<CDBehaviorTemplate> Query(std::function<bool(CDBehaviorTemplate)> predicate);
	std::vector<CDBehaviorTemplate> GetEntries(void) const;
};
