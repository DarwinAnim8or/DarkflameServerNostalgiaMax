#pragma once
#include "CDTable.h"

//Generated by xmlDb2dDatabaseGenerator on 2022-03-04 00:23:32.874163
//DO NOT EDIT THIS FILE MANUALLY!

struct CDBehaviorEffect {
	int effectID;
	std::string effectType;
	std::string effectName;
	int trailID;
	float pcreateDuration;
	std::string soundName;
	std::string animationName;
	bool attachToObject;
	std::string boneName;
	bool useSecondary;
	bool soundIs3D;
	int cameraEffectType;
	float cameraDuration;
	float cameraFrequency;
	float cameraXAmp;
	float cameraYAmp;
	float cameraZAmp;
	float cameraRotFrequency;
	float cameraRoll;
	float cameraPitch;
	float cameraYaw;
	std::string AudioEventGUID;
	int renderEffectType;
	float renderEffectTime;
	float renderStartVal;
	float renderEndVal;
	float renderDelayVal;
	float renderValue1;
	float renderValue2;
	float renderValue3;
	std::string renderRGBA;
	int renderShaderVal;
	int motionID;
	int meshID;
	float meshDuration;
};

class CDBehaviorEffectTable : public CDTable {
private:
	std::vector<CDBehaviorEffect> m_entries;
public:
	CDBehaviorEffectTable();
	~CDBehaviorEffectTable();
	std::string GetName(void) const override;

std::vector<CDBehaviorEffect> Query(std::function<bool(CDBehaviorEffect)> predicate);
	std::vector<CDBehaviorEffect> GetEntries(void) const;
};