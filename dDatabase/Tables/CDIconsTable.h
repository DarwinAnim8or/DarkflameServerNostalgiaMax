#pragma once
#include "CDTable.h"

//Generated by xmlDb2dDatabaseGenerator on 2022-03-04 00:23:32.989854
//DO NOT EDIT THIS FILE MANUALLY!

struct CDIcons {
	int IconID;
	std::string IconPath;
	std::string IconName;
};

class CDIconsTable : public CDTable {
private:
	std::vector<CDIcons> m_entries;
public:
	CDIconsTable();
	~CDIconsTable();
	std::string GetName(void) const override;

std::vector<CDIcons> Query(std::function<bool(CDIcons)> predicate);
	std::vector<CDIcons> GetEntries(void) const;
};