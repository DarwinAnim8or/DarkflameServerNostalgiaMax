#pragma once
#include "CDTable.h"

//Generated by xmlDb2dDatabaseGenerator on 2022-03-04 00:23:33.501487
//DO NOT EDIT THIS FILE MANUALLY!

struct CDZoneSummary {
	int zoneID;
	int type;
	int value;
	int _uniqueID;
};

class CDZoneSummaryTable : public CDTable {
private:
	std::vector<CDZoneSummary> m_entries;
public:
	CDZoneSummaryTable();
	~CDZoneSummaryTable();
	std::string GetName(void) const override;

std::vector<CDZoneSummary> Query(std::function<bool(CDZoneSummary)> predicate);
	std::vector<CDZoneSummary> GetEntries(void) const;
};