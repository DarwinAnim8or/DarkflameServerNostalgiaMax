#pragma once
#include "CDTable.h"

//Generated by xmlDb2dDatabaseGenerator on 2022-03-04 00:23:32.987860
//DO NOT EDIT THIS FILE MANUALLY!

struct CDFootsteps {
	std::string objectType;
	std::string stone;
	std::string grass;
	std::string wood;
	std::string plastic;
	std::string gravel;
	std::string mud;
};

class CDFootstepsTable : public CDTable {
private:
	std::vector<CDFootsteps> m_entries;
public:
	CDFootstepsTable();
	~CDFootstepsTable();
	std::string GetName(void) const override;

std::vector<CDFootsteps> Query(std::function<bool(CDFootsteps)> predicate);
	std::vector<CDFootsteps> GetEntries(void) const;
};
