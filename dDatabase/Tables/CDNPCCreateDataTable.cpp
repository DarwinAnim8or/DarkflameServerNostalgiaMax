#include "CDNPCCreateDataTable.h"
//Generated by xmlDb2dDatabaseGenerator on 2022-03-04 00:23:33.238191
//DO NOT EDIT THIS FILE MANUALLY!

CDNPCCreateDataTable::CDNPCCreateDataTable() {
	unsigned int size = 0;
	auto tableSize = CDClientDatabase::ExecuteQuery("SELECT COUNT(*) FROM NPCCreateData");
		while (!tableSize.eof()) {
		size = tableSize.getIntField(0, 0);
		tableSize.nextRow();
	}

	tableSize.finalize();
	this->m_entries.reserve(size);

	auto tableData = CDClientDatabase::ExecuteQuery("SELECT * FROM NPCCreateData");
	while (!tableData.eof()) {
		CDNPCCreateData entry;
		entry.npcCreateID = tableData.getIntField(0, int{});
		entry.NPCtype = tableData.getStringField(1, std::string{}.c_str());
		entry.Subtype = tableData.getStringField(2, std::string{}.c_str());
		entry.SubSubType = tableData.getStringField(3, std::string{}.c_str());
		entry.animationGroupType = tableData.getStringField(4, std::string{}.c_str());
		entry.RenderAsset = tableData.getStringField(5, std::string{}.c_str());
		entry.ScriptReference = tableData.getIntField(6, int{});
		entry.DestructableReference = tableData.getIntField(7, int{});
		entry.PhysicsReference = tableData.getIntField(8, int{});
		entry.PhysicsTypeRef = tableData.getIntField(9, int{});
		entry.VendorReference = tableData.getIntField(10, int{});
		this->m_entries.push_back(entry);
		tableData.nextRow();
	}

	tableData.finalize();
}

CDNPCCreateDataTable::~CDNPCCreateDataTable() {
}

std::string CDNPCCreateDataTable::GetName(void) const {
	return "NPCCreateData";
}

std::vector<CDNPCCreateData> CDNPCCreateDataTable::Query(std::function<bool(CDNPCCreateData)> predicate) {
	std::vector<CDNPCCreateData> data = cpplinq::from(this->m_entries)
		>> cpplinq::where(predicate)
		>> cpplinq::to_vector();

	return data;
}

std::vector<CDNPCCreateData> CDNPCCreateDataTable::GetEntries(void) const {
	return this->m_entries;
}
