#include "CDAnimationIndexTable.h"
//Generated by xmlDb2dDatabaseGenerator on 2022-03-04 00:23:32.866645
//DO NOT EDIT THIS FILE MANUALLY!

CDAnimationIndexTable::CDAnimationIndexTable() {
	unsigned int size = 0;
	auto tableSize = CDClientDatabase::ExecuteQuery("SELECT COUNT(*) FROM AnimationIndex");
		while (!tableSize.eof()) {
		size = tableSize.getIntField(0, 0);
		tableSize.nextRow();
	}

	tableSize.finalize();
	this->m_entries.reserve(size);

	auto tableData = CDClientDatabase::ExecuteQuery("SELECT * FROM AnimationIndex");
	while (!tableData.eof()) {
		CDAnimationIndex entry;
		entry.animationGroupID = tableData.getIntField(0, int{});
		entry.description = tableData.getStringField(1, std::string{}.c_str());
		entry.groupType = tableData.getStringField(2, std::string{}.c_str());
		this->m_entries.push_back(entry);
		tableData.nextRow();
	}

	tableData.finalize();
}

CDAnimationIndexTable::~CDAnimationIndexTable() {
}

std::string CDAnimationIndexTable::GetName(void) const {
	return "AnimationIndex";
}

std::vector<CDAnimationIndex> CDAnimationIndexTable::Query(std::function<bool(CDAnimationIndex)> predicate) {
	std::vector<CDAnimationIndex> data = cpplinq::from(this->m_entries)
		>> cpplinq::where(predicate)
		>> cpplinq::to_vector();

	return data;
}

std::vector<CDAnimationIndex> CDAnimationIndexTable::GetEntries(void) const {
	return this->m_entries;
}