#include "CDDevModelBehaviorsTable.h"
//Generated by xmlDb2dDatabaseGenerator on 2022-03-04 00:23:32.961930
//DO NOT EDIT THIS FILE MANUALLY!

CDDevModelBehaviorsTable::CDDevModelBehaviorsTable() {
	unsigned int size = 0;
	auto tableSize = CDClientDatabase::ExecuteQuery("SELECT COUNT(*) FROM DevModelBehaviors");
		while (!tableSize.eof()) {
		size = tableSize.getIntField(0, 0);
		tableSize.nextRow();
	}

	tableSize.finalize();
	this->m_entries.reserve(size);

	auto tableData = CDClientDatabase::ExecuteQuery("SELECT * FROM DevModelBehaviors");
	while (!tableData.eof()) {
		CDDevModelBehaviors entry;
		entry.ModelID = tableData.getIntField(0, int{});
		entry.BehaviorID = tableData.getIntField(1, int{});
		this->m_entries.push_back(entry);
		tableData.nextRow();
	}

	tableData.finalize();
}

CDDevModelBehaviorsTable::~CDDevModelBehaviorsTable() {
}

std::string CDDevModelBehaviorsTable::GetName(void) const {
	return "DevModelBehaviors";
}

std::vector<CDDevModelBehaviors> CDDevModelBehaviorsTable::Query(std::function<bool(CDDevModelBehaviors)> predicate) {
	std::vector<CDDevModelBehaviors> data = cpplinq::from(this->m_entries)
		>> cpplinq::where(predicate)
		>> cpplinq::to_vector();

	return data;
}

std::vector<CDDevModelBehaviors> CDDevModelBehaviorsTable::GetEntries(void) const {
	return this->m_entries;
}