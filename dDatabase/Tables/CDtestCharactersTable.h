#pragma once
#include "CDTable.h"

//Generated by xmlDb2dDatabaseGenerator on 2022-03-04 00:23:33.448654
//DO NOT EDIT THIS FILE MANUALLY!

struct CDtestCharacters {
	uint64_t id;
	int propertycloneid;
	std::string name;
	int objid;
	std::string timestamp;
	bool online;
	std::string pendingname;
	bool requiresrename;
};

class CDtestCharactersTable : public CDTable {
private:
	std::vector<CDtestCharacters> m_entries;
public:
	CDtestCharactersTable();
	~CDtestCharactersTable();
	std::string GetName(void) const override;

std::vector<CDtestCharacters> Query(std::function<bool(CDtestCharacters)> predicate);
	std::vector<CDtestCharacters> GetEntries(void) const;
};