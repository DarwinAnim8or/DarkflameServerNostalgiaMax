#include "CDZoneSummaryTable.h"
//Generated by xmlDb2dDatabaseGenerator on 2022-03-04 00:23:33.503482
//DO NOT EDIT THIS FILE MANUALLY!

CDZoneSummaryTable::CDZoneSummaryTable() {
	unsigned int size = 0;
	auto tableSize = CDClientDatabase::ExecuteQuery("SELECT COUNT(*) FROM ZoneSummary");
		while (!tableSize.eof()) {
		size = tableSize.getIntField(0, 0);
		tableSize.nextRow();
	}

	tableSize.finalize();
	this->m_entries.reserve(size);

	auto tableData = CDClientDatabase::ExecuteQuery("SELECT * FROM ZoneSummary");
	while (!tableData.eof()) {
		CDZoneSummary entry;
		entry.zoneID = tableData.getIntField(0, int{});
		entry.type = tableData.getIntField(1, int{});
		entry.value = tableData.getIntField(2, int{});
		entry._uniqueID = tableData.getIntField(3, int{});
		this->m_entries.push_back(entry);
		tableData.nextRow();
	}

	tableData.finalize();
}

CDZoneSummaryTable::~CDZoneSummaryTable() {
}

std::string CDZoneSummaryTable::GetName(void) const {
	return "ZoneSummary";
}

std::vector<CDZoneSummary> CDZoneSummaryTable::Query(std::function<bool(CDZoneSummary)> predicate) {
	std::vector<CDZoneSummary> data = cpplinq::from(this->m_entries)
		>> cpplinq::where(predicate)
		>> cpplinq::to_vector();

	return data;
}

std::vector<CDZoneSummary> CDZoneSummaryTable::GetEntries(void) const {
	return this->m_entries;
}