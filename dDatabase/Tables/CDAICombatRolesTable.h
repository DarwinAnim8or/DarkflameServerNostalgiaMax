#pragma once
#include "CDTable.h"

//Generated by xmlDb2dDatabaseGenerator on 2022-03-04 00:23:32.858188
//DO NOT EDIT THIS FILE MANUALLY!

struct CDAICombatRoles {
	int id;
	int preferredRole;
	std::string description;
	float specifiedMinRangeNOUSE;
	float specifiedMaxRangeNOUSE;
	float specificMinRange;
	float specificMaxRange;
};

class CDAICombatRolesTable : public CDTable {
private:
	std::vector<CDAICombatRoles> m_entries;
public:
	CDAICombatRolesTable();
	~CDAICombatRolesTable();
	std::string GetName(void) const override;

std::vector<CDAICombatRoles> Query(std::function<bool(CDAICombatRoles)> predicate);
	std::vector<CDAICombatRoles> GetEntries(void) const;
};