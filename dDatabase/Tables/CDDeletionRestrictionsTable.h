#pragma once
#include "CDTable.h"

//Generated by xmlDb2dDatabaseGenerator on 2022-03-04 00:23:32.948964
//DO NOT EDIT THIS FILE MANUALLY!

struct CDDeletionRestrictions {
	int id;
	bool restricted;
	std::string ids;
	int checkType;
};

class CDDeletionRestrictionsTable : public CDTable {
private:
	std::vector<CDDeletionRestrictions> m_entries;
public:
	CDDeletionRestrictionsTable();
	~CDDeletionRestrictionsTable();
	std::string GetName(void) const override;

std::vector<CDDeletionRestrictions> Query(std::function<bool(CDDeletionRestrictions)> predicate);
	std::vector<CDDeletionRestrictions> GetEntries(void) const;
};