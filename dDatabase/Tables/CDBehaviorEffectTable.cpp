#include "CDBehaviorEffectTable.h"
//Generated by xmlDb2dDatabaseGenerator on 2022-03-04 00:23:32.876159
//DO NOT EDIT THIS FILE MANUALLY!

CDBehaviorEffectTable::CDBehaviorEffectTable() {
	unsigned int size = 0;
	auto tableSize = CDClientDatabase::ExecuteQuery("SELECT COUNT(*) FROM BehaviorEffect");
		while (!tableSize.eof()) {
		size = tableSize.getIntField(0, 0);
		tableSize.nextRow();
	}

	tableSize.finalize();
	this->m_entries.reserve(size);

	auto tableData = CDClientDatabase::ExecuteQuery("SELECT * FROM BehaviorEffect");
	while (!tableData.eof()) {
		CDBehaviorEffect entry;
		entry.effectID = tableData.getIntField(0, int{});
		entry.effectType = tableData.getStringField(1, std::string{}.c_str());
		entry.effectName = tableData.getStringField(2, std::string{}.c_str());
		entry.trailID = tableData.getIntField(3, int{});
		entry.pcreateDuration = tableData.getFloatField(4, float{});
		entry.soundName = tableData.getStringField(5, std::string{}.c_str());
		entry.animationName = tableData.getStringField(6, std::string{}.c_str());
		entry.attachToObject = tableData.getIntField(7, bool{});
		entry.boneName = tableData.getStringField(8, std::string{}.c_str());
		entry.useSecondary = tableData.getIntField(9, bool{});
		entry.soundIs3D = tableData.getIntField(10, bool{});
		entry.cameraEffectType = tableData.getIntField(11, int{});
		entry.cameraDuration = tableData.getFloatField(12, float{});
		entry.cameraFrequency = tableData.getFloatField(13, float{});
		entry.cameraXAmp = tableData.getFloatField(14, float{});
		entry.cameraYAmp = tableData.getFloatField(15, float{});
		entry.cameraZAmp = tableData.getFloatField(16, float{});
		entry.cameraRotFrequency = tableData.getFloatField(17, float{});
		entry.cameraRoll = tableData.getFloatField(18, float{});
		entry.cameraPitch = tableData.getFloatField(19, float{});
		entry.cameraYaw = tableData.getFloatField(20, float{});
		entry.AudioEventGUID = tableData.getStringField(21, std::string{}.c_str());
		entry.renderEffectType = tableData.getIntField(22, int{});
		entry.renderEffectTime = tableData.getFloatField(23, float{});
		entry.renderStartVal = tableData.getFloatField(24, float{});
		entry.renderEndVal = tableData.getFloatField(25, float{});
		entry.renderDelayVal = tableData.getFloatField(26, float{});
		entry.renderValue1 = tableData.getFloatField(27, float{});
		entry.renderValue2 = tableData.getFloatField(28, float{});
		entry.renderValue3 = tableData.getFloatField(29, float{});
		entry.renderRGBA = tableData.getStringField(30, std::string{}.c_str());
		entry.renderShaderVal = tableData.getIntField(31, int{});
		entry.motionID = tableData.getIntField(32, int{});
		entry.meshID = tableData.getIntField(33, int{});
		entry.meshDuration = tableData.getFloatField(34, float{});
		this->m_entries.push_back(entry);
		tableData.nextRow();
	}

	tableData.finalize();
}

CDBehaviorEffectTable::~CDBehaviorEffectTable() {
}

std::string CDBehaviorEffectTable::GetName(void) const {
	return "BehaviorEffect";
}

std::vector<CDBehaviorEffect> CDBehaviorEffectTable::Query(std::function<bool(CDBehaviorEffect)> predicate) {
	std::vector<CDBehaviorEffect> data = cpplinq::from(this->m_entries)
		>> cpplinq::where(predicate)
		>> cpplinq::to_vector();

	return data;
}

std::vector<CDBehaviorEffect> CDBehaviorEffectTable::GetEntries(void) const {
	return this->m_entries;
}
