#include "CDSceneTableTable.h"
//Generated by xmlDb2dDatabaseGenerator on 2022-03-04 00:23:33.399760
//DO NOT EDIT THIS FILE MANUALLY!

CDSceneTableTable::CDSceneTableTable() {
	unsigned int size = 0;
	auto tableSize = CDClientDatabase::ExecuteQuery("SELECT COUNT(*) FROM SceneTable");
		while (!tableSize.eof()) {
		size = tableSize.getIntField(0, 0);
		tableSize.nextRow();
	}

	tableSize.finalize();
	this->m_entries.reserve(size);

	auto tableData = CDClientDatabase::ExecuteQuery("SELECT * FROM SceneTable");
	while (!tableData.eof()) {
		CDSceneTable entry;
		entry.sceneID = tableData.getIntField(0, int{});
		entry.sceneName = tableData.getStringField(1, std::string{}.c_str());
		this->m_entries.push_back(entry);
		tableData.nextRow();
	}

	tableData.finalize();
}

CDSceneTableTable::~CDSceneTableTable() {
}

std::string CDSceneTableTable::GetName(void) const {
	return "SceneTable";
}

std::vector<CDSceneTable> CDSceneTableTable::Query(std::function<bool(CDSceneTable)> predicate) {
	std::vector<CDSceneTable> data = cpplinq::from(this->m_entries)
		>> cpplinq::where(predicate)
		>> cpplinq::to_vector();

	return data;
}

std::vector<CDSceneTable> CDSceneTableTable::GetEntries(void) const {
	return this->m_entries;
}