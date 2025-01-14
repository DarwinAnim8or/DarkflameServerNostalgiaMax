#pragma once
#include "CDTable.h"

//Generated by xmlDb2dDatabaseGenerator on 2022-03-04 00:23:33.224228
//DO NOT EDIT THIS FILE MANUALLY!

struct CDModelBehavior {
	int id;
	std::string definitionXMLfilename;
};

class CDModelBehaviorTable : public CDTable {
private:
	std::vector<CDModelBehavior> m_entries;
public:
	CDModelBehaviorTable();
	~CDModelBehaviorTable();
	std::string GetName(void) const override;

std::vector<CDModelBehavior> Query(std::function<bool(CDModelBehavior)> predicate);
	std::vector<CDModelBehavior> GetEntries(void) const;
};
