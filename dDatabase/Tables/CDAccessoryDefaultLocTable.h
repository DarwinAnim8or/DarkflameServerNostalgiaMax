#pragma once
#include "CDTable.h"

//Generated by xmlDb2dDatabaseGenerator on 2022-03-04 00:23:32.840625
//DO NOT EDIT THIS FILE MANUALLY!

struct CDAccessoryDefaultLoc {
	int GroupID;
	std::string Description;
	float Pos_X;
	float Pos_Y;
	float Pos_Z;
	float Rot_X;
	float Rot_Y;
	float Rot_Z;
};

class CDAccessoryDefaultLocTable : public CDTable {
private:
	std::vector<CDAccessoryDefaultLoc> m_entries;
public:
	CDAccessoryDefaultLocTable();
	~CDAccessoryDefaultLocTable();
	std::string GetName(void) const override;

std::vector<CDAccessoryDefaultLoc> Query(std::function<bool(CDAccessoryDefaultLoc)> predicate);
	std::vector<CDAccessoryDefaultLoc> GetEntries(void) const;
};
