#pragma once
#include "CDTable.h"

//Generated by xmlDb2dDatabaseGenerator on 2022-03-04 00:23:32.892149
//DO NOT EDIT THIS FILE MANUALLY!

struct CDBlueprints {
	uint64_t id;
	std::string name;
	std::string description;
	uint64_t accountid;
	uint64_t characterid;
	int price;
	int rating;
	int categoryid;
	std::string lxfpath;
	bool deleted;
	std::string created;
	std::string modified;
};

class CDBlueprintsTable : public CDTable {
private:
	std::vector<CDBlueprints> m_entries;
public:
	CDBlueprintsTable();
	~CDBlueprintsTable();
	std::string GetName(void) const override;

std::vector<CDBlueprints> Query(std::function<bool(CDBlueprints)> predicate);
	std::vector<CDBlueprints> GetEntries(void) const;
};