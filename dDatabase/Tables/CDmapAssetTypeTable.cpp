#include "CDmapAssetTypeTable.h"
//Generated by xmlDb2dDatabaseGenerator on 2022-03-04 00:23:33.140655
//DO NOT EDIT THIS FILE MANUALLY!

CDmapAssetTypeTable::CDmapAssetTypeTable() {
	unsigned int size = 0;
	auto tableSize = CDClientDatabase::ExecuteQuery("SELECT COUNT(*) FROM mapAssetType");
		while (!tableSize.eof()) {
		size = tableSize.getIntField(0, 0);
		tableSize.nextRow();
	}

	tableSize.finalize();
	this->m_entries.reserve(size);

	auto tableData = CDClientDatabase::ExecuteQuery("SELECT * FROM mapAssetType");
	while (!tableData.eof()) {
		CDmapAssetType entry;
		entry.id = tableData.getIntField(0, int{});
		entry.label = tableData.getStringField(1, std::string{}.c_str());
		entry.pathdir = tableData.getStringField(2, std::string{}.c_str());
		entry.typelabel = tableData.getStringField(3, std::string{}.c_str());
		this->m_entries.push_back(entry);
		tableData.nextRow();
	}

	tableData.finalize();
}

CDmapAssetTypeTable::~CDmapAssetTypeTable() {
}

std::string CDmapAssetTypeTable::GetName(void) const {
	return "mapAssetType";
}

std::vector<CDmapAssetType> CDmapAssetTypeTable::Query(std::function<bool(CDmapAssetType)> predicate) {
	std::vector<CDmapAssetType> data = cpplinq::from(this->m_entries)
		>> cpplinq::where(predicate)
		>> cpplinq::to_vector();

	return data;
}

std::vector<CDmapAssetType> CDmapAssetTypeTable::GetEntries(void) const {
	return this->m_entries;
}
