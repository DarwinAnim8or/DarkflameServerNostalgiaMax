#pragma once
#include "CDTable.h"

//Generated by xmlDb2dDatabaseGenerator on 2022-03-04 00:23:33.432671
//DO NOT EDIT THIS FILE MANUALLY!

struct CDSpeedchatMenu {
	int id;
	int parentId;
	int emoteId;
	std::string menuText;
	std::string imageName;
};

class CDSpeedchatMenuTable : public CDTable {
private:
	std::vector<CDSpeedchatMenu> m_entries;
public:
	CDSpeedchatMenuTable();
	~CDSpeedchatMenuTable();
	std::string GetName(void) const override;

std::vector<CDSpeedchatMenu> Query(std::function<bool(CDSpeedchatMenu)> predicate);
	std::vector<CDSpeedchatMenu> GetEntries(void) const;
};