#include "CDRenderComponentTable.h"
//Generated by xmlDb2dDatabaseGenerator on 2022-03-04 00:23:33.371835
//DO NOT EDIT THIS FILE MANUALLY!

CDRenderComponentTable::CDRenderComponentTable() {
	unsigned int size = 0;
	auto tableSize = CDClientDatabase::ExecuteQuery("SELECT COUNT(*) FROM RenderComponent");
		while (!tableSize.eof()) {
		size = tableSize.getIntField(0, 0);
		tableSize.nextRow();
	}

	tableSize.finalize();
	this->m_entries.reserve(size);

	auto tableData = CDClientDatabase::ExecuteQuery("SELECT * FROM RenderComponent");
	while (!tableData.eof()) {
		CDRenderComponent entry;
		entry.id = tableData.getIntField(0, int{});
		entry.render_asset = tableData.getStringField(1, std::string{}.c_str());
		entry.icon_asset = tableData.getStringField(2, std::string{}.c_str());
		entry.IconID = tableData.getIntField(3, int{});
		entry.shader_id = tableData.getIntField(4, int{});
		entry.effect1 = tableData.getIntField(5, int{});
		entry.effect2 = tableData.getIntField(6, int{});
		entry.effect3 = tableData.getIntField(7, int{});
		entry.effect4 = tableData.getIntField(8, int{});
		entry.effect5 = tableData.getIntField(9, int{});
		entry.effect6 = tableData.getIntField(10, int{});
		entry.footstepType = tableData.getStringField(11, std::string{}.c_str());
		entry.animationGroupID = tableData.getIntField(12, int{});
		entry.fade = tableData.getIntField(13, bool{});
		entry.usedropshadow = tableData.getIntField(14, bool{});
		entry.preloadAnimations = tableData.getIntField(15, bool{});
		entry.fadeInTime = tableData.getFloatField(16, float{});
		entry.maxShadowDistance = tableData.getFloatField(17, float{});
		entry.ignoreCameraCollision = tableData.getIntField(18, bool{});
		entry.renderComponentLOD1 = tableData.getIntField(19, int{});
		entry.renderComponentLOD2 = tableData.getIntField(20, int{});
		entry.gradualSnap = tableData.getIntField(21, bool{});
		entry.animationFlag = tableData.getIntField(22, int{});
		this->m_entries.push_back(entry);
		tableData.nextRow();
	}

	tableData.finalize();
}

CDRenderComponentTable::~CDRenderComponentTable() {
}

std::string CDRenderComponentTable::GetName(void) const {
	return "RenderComponent";
}

std::vector<CDRenderComponent> CDRenderComponentTable::Query(std::function<bool(CDRenderComponent)> predicate) {
	std::vector<CDRenderComponent> data = cpplinq::from(this->m_entries)
		>> cpplinq::where(predicate)
		>> cpplinq::to_vector();

	return data;
}

std::vector<CDRenderComponent> CDRenderComponentTable::GetEntries(void) const {
	return this->m_entries;
}
