#include "CDTextLanguageTable.h"
//Generated by xmlDb2dDatabaseGenerator on 2022-03-04 00:23:33.457605
//DO NOT EDIT THIS FILE MANUALLY!

CDTextLanguageTable::CDTextLanguageTable() {
	unsigned int size = 0;
	auto tableSize = CDClientDatabase::ExecuteQuery("SELECT COUNT(*) FROM TextLanguage");
		while (!tableSize.eof()) {
		size = tableSize.getIntField(0, 0);
		tableSize.nextRow();
	}

	tableSize.finalize();
	this->m_entries.reserve(size);

	auto tableData = CDClientDatabase::ExecuteQuery("SELECT * FROM TextLanguage");
	while (!tableData.eof()) {
		CDTextLanguage entry;
		entry.TextID = tableData.getIntField(0, int{});
		entry.LanguageID = tableData.getIntField(1, int{});
		entry.Text = tableData.getStringField(2, std::string{}.c_str());
		this->m_entries.push_back(entry);
		tableData.nextRow();
	}

	tableData.finalize();
}

CDTextLanguageTable::~CDTextLanguageTable() {
}

std::string CDTextLanguageTable::GetName(void) const {
	return "TextLanguage";
}

std::vector<CDTextLanguage> CDTextLanguageTable::Query(std::function<bool(CDTextLanguage)> predicate) {
	std::vector<CDTextLanguage> data = cpplinq::from(this->m_entries)
		>> cpplinq::where(predicate)
		>> cpplinq::to_vector();

	return data;
}

std::vector<CDTextLanguage> CDTextLanguageTable::GetEntries(void) const {
	return this->m_entries;
}
