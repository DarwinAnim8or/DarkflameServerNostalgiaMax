#include "CDDeletionRestrictionsTable.h"
//Generated by xmlDb2dDatabaseGenerator on 2022-03-04 00:23:32.950958
//DO NOT EDIT THIS FILE MANUALLY!

CDDeletionRestrictionsTable::CDDeletionRestrictionsTable() {
	unsigned int size = 0;
	auto tableSize = CDClientDatabase::ExecuteQuery("SELECT COUNT(*) FROM DeletionRestrictions");
		while (!tableSize.eof()) {
		size = tableSize.getIntField(0, 0);
		tableSize.nextRow();
	}

	tableSize.finalize();
	this->m_entries.reserve(size);

	auto tableData = CDClientDatabase::ExecuteQuery("SELECT * FROM DeletionRestrictions");
	while (!tableData.eof()) {
		CDDeletionRestrictions entry;
		entry.id = tableData.getIntField(0, int{});
		entry.restricted = tableData.getIntField(1, bool{});
		entry.ids = tableData.getStringField(2, std::string{}.c_str());
		entry.checkType = tableData.getIntField(3, int{});
		this->m_entries.push_back(entry);
		tableData.nextRow();
	}

	tableData.finalize();
}

CDDeletionRestrictionsTable::~CDDeletionRestrictionsTable() {
}

std::string CDDeletionRestrictionsTable::GetName(void) const {
	return "DeletionRestrictions";
}

std::vector<CDDeletionRestrictions> CDDeletionRestrictionsTable::Query(std::function<bool(CDDeletionRestrictions)> predicate) {
	std::vector<CDDeletionRestrictions> data = cpplinq::from(this->m_entries)
		>> cpplinq::where(predicate)
		>> cpplinq::to_vector();

	return data;
}

std::vector<CDDeletionRestrictions> CDDeletionRestrictionsTable::GetEntries(void) const {
	return this->m_entries;
}
