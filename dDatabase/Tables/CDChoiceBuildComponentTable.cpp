#include "CDChoiceBuildComponentTable.h"
//Generated by xmlDb2dDatabaseGenerator on 2022-03-04 00:23:32.913060
//DO NOT EDIT THIS FILE MANUALLY!

CDChoiceBuildComponentTable::CDChoiceBuildComponentTable() {
	unsigned int size = 0;
	auto tableSize = CDClientDatabase::ExecuteQuery("SELECT COUNT(*) FROM ChoiceBuildComponent");
		while (!tableSize.eof()) {
		size = tableSize.getIntField(0, 0);
		tableSize.nextRow();
	}

	tableSize.finalize();
	this->m_entries.reserve(size);

	auto tableData = CDClientDatabase::ExecuteQuery("SELECT * FROM ChoiceBuildComponent");
	while (!tableData.eof()) {
		CDChoiceBuildComponent entry;
		entry.id = tableData.getIntField(0, int{});
		entry.selections = tableData.getStringField(1, std::string{}.c_str());
		entry.imaginationOverride = tableData.getIntField(2, int{});
		this->m_entries.push_back(entry);
		tableData.nextRow();
	}

	tableData.finalize();
}

CDChoiceBuildComponentTable::~CDChoiceBuildComponentTable() {
}

std::string CDChoiceBuildComponentTable::GetName(void) const {
	return "ChoiceBuildComponent";
}

std::vector<CDChoiceBuildComponent> CDChoiceBuildComponentTable::Query(std::function<bool(CDChoiceBuildComponent)> predicate) {
	std::vector<CDChoiceBuildComponent> data = cpplinq::from(this->m_entries)
		>> cpplinq::where(predicate)
		>> cpplinq::to_vector();

	return data;
}

std::vector<CDChoiceBuildComponent> CDChoiceBuildComponentTable::GetEntries(void) const {
	return this->m_entries;
}