#include "CDCurrencyTableTable.h"
//Generated by xmlDb2dDatabaseGenerator on 2022-03-04 00:23:32.944043
//DO NOT EDIT THIS FILE MANUALLY!

CDCurrencyTableTable::CDCurrencyTableTable() {
	unsigned int size = 0;
	auto tableSize = CDClientDatabase::ExecuteQuery("SELECT COUNT(*) FROM CurrencyTable");
		while (!tableSize.eof()) {
		size = tableSize.getIntField(0, 0);
		tableSize.nextRow();
	}

	tableSize.finalize();
	this->m_entries.reserve(size);

	auto tableData = CDClientDatabase::ExecuteQuery("SELECT * FROM CurrencyTable");
	while (!tableData.eof()) {
		CDCurrencyTable entry;
		entry.currencyIndex = tableData.getIntField(0, int{});
		entry.npcminlevel = tableData.getIntField(1, int{});
		entry.minvalue = tableData.getIntField(2, int{});
		entry.maxvalue = tableData.getIntField(3, int{});
		entry.id = tableData.getIntField(4, int{});
		this->m_entries.push_back(entry);
		tableData.nextRow();
	}

	tableData.finalize();
}

CDCurrencyTableTable::~CDCurrencyTableTable() {
}

std::string CDCurrencyTableTable::GetName(void) const {
	return "CurrencyTable";
}

std::vector<CDCurrencyTable> CDCurrencyTableTable::Query(std::function<bool(CDCurrencyTable)> predicate) {
	std::vector<CDCurrencyTable> data = cpplinq::from(this->m_entries)
		>> cpplinq::where(predicate)
		>> cpplinq::to_vector();

	return data;
}

std::vector<CDCurrencyTable> CDCurrencyTableTable::GetEntries(void) const {
	return this->m_entries;
}
