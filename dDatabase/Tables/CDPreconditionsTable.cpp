#include "CDPreconditionsTable.h"
//Generated by xmlDb2dDatabaseGenerator on 2022-03-04 00:23:33.286063
//DO NOT EDIT THIS FILE MANUALLY!

CDPreconditionsTable::CDPreconditionsTable() {
	unsigned int size = 0;
	auto tableSize = CDClientDatabase::ExecuteQuery("SELECT COUNT(*) FROM Preconditions");
		while (!tableSize.eof()) {
		size = tableSize.getIntField(0, 0);
		tableSize.nextRow();
	}

	tableSize.finalize();
	this->m_entries.reserve(size);

	auto tableData = CDClientDatabase::ExecuteQuery("SELECT * FROM Preconditions");
	while (!tableData.eof()) {
		CDPreconditions entry;
		entry.id = tableData.getIntField(0, int{});
		entry.type = tableData.getIntField(1, int{});
		entry.description = tableData.getStringField(2, std::string{}.c_str());
		entry.targetLOT = tableData.getStringField(3, std::string{}.c_str());
		entry.targetGroup = tableData.getStringField(4, std::string{}.c_str());
		entry.targetCount = tableData.getIntField(5, int{});
		entry.FailureReason = tableData.getStringField(6, std::string{}.c_str());
		this->m_entries.push_back(entry);
		tableData.nextRow();
	}

	tableData.finalize();
}

CDPreconditionsTable::~CDPreconditionsTable() {
}

std::string CDPreconditionsTable::GetName(void) const {
	return "Preconditions";
}

std::vector<CDPreconditions> CDPreconditionsTable::Query(std::function<bool(CDPreconditions)> predicate) {
	std::vector<CDPreconditions> data = cpplinq::from(this->m_entries)
		>> cpplinq::where(predicate)
		>> cpplinq::to_vector();

	return data;
}

std::vector<CDPreconditions> CDPreconditionsTable::GetEntries(void) const {
	return this->m_entries;
}