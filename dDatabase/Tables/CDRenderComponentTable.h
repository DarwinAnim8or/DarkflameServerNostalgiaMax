#pragma once
#include "CDTable.h"

//Generated by xmlDb2dDatabaseGenerator on 2022-03-04 00:23:33.369855
//DO NOT EDIT THIS FILE MANUALLY!

struct CDRenderComponent {
	int id;
	std::string render_asset;
	std::string icon_asset;
	int IconID;
	int shader_id;
	int effect1;
	int effect2;
	int effect3;
	int effect4;
	int effect5;
	int effect6;
	std::string footstepType;
	int animationGroupID;
	bool fade;
	bool usedropshadow;
	bool preloadAnimations;
	float fadeInTime;
	float maxShadowDistance;
	bool ignoreCameraCollision;
	int renderComponentLOD1;
	int renderComponentLOD2;
	bool gradualSnap;
	int animationFlag;
};

class CDRenderComponentTable : public CDTable {
private:
	std::vector<CDRenderComponent> m_entries;
public:
	CDRenderComponentTable();
	~CDRenderComponentTable();
	std::string GetName(void) const override;

std::vector<CDRenderComponent> Query(std::function<bool(CDRenderComponent)> predicate);
	std::vector<CDRenderComponent> GetEntries(void) const;
};
