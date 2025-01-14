#include "CDRenderComponentFlashTable.h"
//Generated by xmlDb2dDatabaseGenerator on 2022-03-04 00:23:33.378816
//DO NOT EDIT THIS FILE MANUALLY!

CDRenderComponentFlashTable::CDRenderComponentFlashTable() {
	unsigned int size = 0;
	auto tableSize = CDClientDatabase::ExecuteQuery("SELECT COUNT(*) FROM RenderComponentFlash");
		while (!tableSize.eof()) {
		size = tableSize.getIntField(0, 0);
		tableSize.nextRow();
	}

	tableSize.finalize();
	this->m_entries.reserve(size);

	auto tableData = CDClientDatabase::ExecuteQuery("SELECT * FROM RenderComponentFlash");
	while (!tableData.eof()) {
		CDRenderComponentFlash entry;
		entry.id = tableData.getIntField(0, int{});
		entry.interactive = tableData.getIntField(1, bool{});
		entry.animated = tableData.getIntField(2, bool{});
		entry.nodeName = tableData.getStringField(3, std::string{}.c_str());
		entry.flashPath = tableData.getStringField(4, std::string{}.c_str());
		entry.elementName = tableData.getStringField(5, std::string{}.c_str());
		entry._uid = tableData.getIntField(6, int{});
		this->m_entries.push_back(entry);
		tableData.nextRow();
	}

	tableData.finalize();
}

CDRenderComponentFlashTable::~CDRenderComponentFlashTable() {
}

std::string CDRenderComponentFlashTable::GetName(void) const {
	return "RenderComponentFlash";
}

std::vector<CDRenderComponentFlash> CDRenderComponentFlashTable::Query(std::function<bool(CDRenderComponentFlash)> predicate) {
	std::vector<CDRenderComponentFlash> data = cpplinq::from(this->m_entries)
		>> cpplinq::where(predicate)
		>> cpplinq::to_vector();

	return data;
}

std::vector<CDRenderComponentFlash> CDRenderComponentFlashTable::GetEntries(void) const {
	return this->m_entries;
}
