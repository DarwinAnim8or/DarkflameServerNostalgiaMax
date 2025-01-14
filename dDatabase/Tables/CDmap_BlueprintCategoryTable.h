#pragma once
#include "CDTable.h"

//Generated by xmlDb2dDatabaseGenerator on 2022-03-04 00:23:33.133471
//DO NOT EDIT THIS FILE MANUALLY!

struct CDmap_BlueprintCategory {
	int id;
	std::string description;
	bool enabled;
};

class CDmap_BlueprintCategoryTable : public CDTable {
private:
	std::vector<CDmap_BlueprintCategory> m_entries;
public:
	CDmap_BlueprintCategoryTable();
	~CDmap_BlueprintCategoryTable();
	std::string GetName(void) const override;

std::vector<CDmap_BlueprintCategory> Query(std::function<bool(CDmap_BlueprintCategory)> predicate);
	std::vector<CDmap_BlueprintCategory> GetEntries(void) const;
};
