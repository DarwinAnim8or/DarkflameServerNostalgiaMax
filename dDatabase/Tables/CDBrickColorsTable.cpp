#include "CDBrickColorsTable.h"
//Generated by xmlDb2dDatabaseGenerator on 2022-03-04 00:23:32.901091
//DO NOT EDIT THIS FILE MANUALLY!

CDBrickColorsTable::CDBrickColorsTable() {
	unsigned int size = 0;
	auto tableSize = CDClientDatabase::ExecuteQuery("SELECT COUNT(*) FROM BrickColors");
		while (!tableSize.eof()) {
		size = tableSize.getIntField(0, 0);
		tableSize.nextRow();
	}

	tableSize.finalize();
	this->m_entries.reserve(size);

	auto tableData = CDClientDatabase::ExecuteQuery("SELECT * FROM BrickColors");
	while (!tableData.eof()) {
		CDBrickColors entry;
		entry.id = tableData.getIntField(0, int{});
		entry.red = tableData.getFloatField(1, float{});
		entry.green = tableData.getFloatField(2, float{});
		entry.blue = tableData.getFloatField(3, float{});
		entry.alpha = tableData.getFloatField(4, float{});
		entry.legopaletteid = tableData.getIntField(5, int{});
		entry.description = tableData.getStringField(6, std::string{}.c_str());
		entry.validTypes = tableData.getIntField(7, int{});
		entry.validCharacters = tableData.getIntField(8, int{});
		entry.factoryValid = tableData.getIntField(9, bool{});
		this->m_entries.push_back(entry);
		tableData.nextRow();
	}

	tableData.finalize();
}

CDBrickColorsTable::~CDBrickColorsTable() {
}

std::string CDBrickColorsTable::GetName(void) const {
	return "BrickColors";
}

std::vector<CDBrickColors> CDBrickColorsTable::Query(std::function<bool(CDBrickColors)> predicate) {
	std::vector<CDBrickColors> data = cpplinq::from(this->m_entries)
		>> cpplinq::where(predicate)
		>> cpplinq::to_vector();

	return data;
}

std::vector<CDBrickColors> CDBrickColorsTable::GetEntries(void) const {
	return this->m_entries;
}