#include "CDCurrencyDenominationsTable.h"
//Generated by xmlDb2dDatabaseGenerator on 2022-03-04 00:23:32.934003
//DO NOT EDIT THIS FILE MANUALLY!

CDCurrencyDenominationsTable::CDCurrencyDenominationsTable() {
	unsigned int size = 0;
	auto tableSize = CDClientDatabase::ExecuteQuery("SELECT COUNT(*) FROM CurrencyDenominations");
		while (!tableSize.eof()) {
		size = tableSize.getIntField(0, 0);
		tableSize.nextRow();
	}

	tableSize.finalize();
	this->m_entries.reserve(size);

	auto tableData = CDClientDatabase::ExecuteQuery("SELECT * FROM CurrencyDenominations");
	while (!tableData.eof()) {
		CDCurrencyDenominations entry;
		entry.value = tableData.getIntField(0, int{});
		entry.objectid = tableData.getIntField(1, int{});
		this->m_entries.push_back(entry);
		tableData.nextRow();
	}

	tableData.finalize();
}

CDCurrencyDenominationsTable::~CDCurrencyDenominationsTable() {
}

std::string CDCurrencyDenominationsTable::GetName(void) const {
	return "CurrencyDenominations";
}

std::vector<CDCurrencyDenominations> CDCurrencyDenominationsTable::Query(std::function<bool(CDCurrencyDenominations)> predicate) {
	std::vector<CDCurrencyDenominations> data = cpplinq::from(this->m_entries)
		>> cpplinq::where(predicate)
		>> cpplinq::to_vector();

	return data;
}

std::vector<CDCurrencyDenominations> CDCurrencyDenominationsTable::GetEntries(void) const {
	return this->m_entries;
}