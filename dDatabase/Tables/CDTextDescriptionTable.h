#pragma once
#include "CDTable.h"

//Generated by xmlDb2dDatabaseGenerator on 2022-03-04 00:23:33.454612
//DO NOT EDIT THIS FILE MANUALLY!

struct CDTextDescription {
	int TextID;
	std::string TestDescription;
};

class CDTextDescriptionTable : public CDTable {
private:
	std::vector<CDTextDescription> m_entries;
public:
	CDTextDescriptionTable();
	~CDTextDescriptionTable();
	std::string GetName(void) const override;

std::vector<CDTextDescription> Query(std::function<bool(CDTextDescription)> predicate);
	std::vector<CDTextDescription> GetEntries(void) const;
};
