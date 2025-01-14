#include "CDLanguageTypeTable.h"
//Generated by xmlDb2dDatabaseGenerator on 2022-03-04 00:23:33.100558
//DO NOT EDIT THIS FILE MANUALLY!

CDLanguageTypeTable::CDLanguageTypeTable() {
	unsigned int size = 0;
	auto tableSize = CDClientDatabase::ExecuteQuery("SELECT COUNT(*) FROM LanguageType");
		while (!tableSize.eof()) {
		size = tableSize.getIntField(0, 0);
		tableSize.nextRow();
	}

	tableSize.finalize();
	this->m_entries.reserve(size);

	auto tableData = CDClientDatabase::ExecuteQuery("SELECT * FROM LanguageType");
	while (!tableData.eof()) {
		CDLanguageType entry;
		entry.LanguageID = tableData.getIntField(0, int{});
		entry.LanguageDescription = tableData.getStringField(1, std::string{}.c_str());
		this->m_entries.push_back(entry);
		tableData.nextRow();
	}

	tableData.finalize();
}

CDLanguageTypeTable::~CDLanguageTypeTable() {
}

std::string CDLanguageTypeTable::GetName(void) const {
	return "LanguageType";
}

std::vector<CDLanguageType> CDLanguageTypeTable::Query(std::function<bool(CDLanguageType)> predicate) {
	std::vector<CDLanguageType> data = cpplinq::from(this->m_entries)
		>> cpplinq::where(predicate)
		>> cpplinq::to_vector();

	return data;
}

std::vector<CDLanguageType> CDLanguageTypeTable::GetEntries(void) const {
	return this->m_entries;
}
