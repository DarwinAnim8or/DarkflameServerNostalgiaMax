#pragma once
#include "CDTable.h"

//Generated by xmlDb2dDatabaseGenerator on 2022-03-04 00:23:33.382804
//DO NOT EDIT THIS FILE MANUALLY!

struct CDRenderIconAssets {
	int id;
	std::string icon_asset;
	std::string blank_column;
};

class CDRenderIconAssetsTable : public CDTable {
private:
	std::vector<CDRenderIconAssets> m_entries;
public:
	CDRenderIconAssetsTable();
	~CDRenderIconAssetsTable();
	std::string GetName(void) const override;

std::vector<CDRenderIconAssets> Query(std::function<bool(CDRenderIconAssets)> predicate);
	std::vector<CDRenderIconAssets> GetEntries(void) const;
};
