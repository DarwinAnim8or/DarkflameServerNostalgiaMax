#pragma once
#include "CDTable.h"

//Generated by xmlDb2dDatabaseGenerator on 2022-03-04 00:23:33.436660
//DO NOT EDIT THIS FILE MANUALLY!

struct CDSurfaceType {
	int SurfaceType;
	std::string Name;
	std::string FootstepNDAudioMetaEventSetName;
};

class CDSurfaceTypeTable : public CDTable {
private:
	std::vector<CDSurfaceType> m_entries;
public:
	CDSurfaceTypeTable();
	~CDSurfaceTypeTable();
	std::string GetName(void) const override;

std::vector<CDSurfaceType> Query(std::function<bool(CDSurfaceType)> predicate);
	std::vector<CDSurfaceType> GetEntries(void) const;
};