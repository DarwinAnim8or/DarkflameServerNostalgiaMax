#include "CDPetComponentTable.h"
//Generated by xmlDb2dDatabaseGenerator on 2022-03-04 00:23:33.267114
//DO NOT EDIT THIS FILE MANUALLY!

CDPetComponentTable::CDPetComponentTable() {
	unsigned int size = 0;
	auto tableSize = CDClientDatabase::ExecuteQuery("SELECT COUNT(*) FROM PetComponent");
		while (!tableSize.eof()) {
		size = tableSize.getIntField(0, 0);
		tableSize.nextRow();
	}

	tableSize.finalize();
	this->m_entries.reserve(size);

	auto tableData = CDClientDatabase::ExecuteQuery("SELECT * FROM PetComponent");
	while (!tableData.eof()) {
		CDPetComponent entry;
		entry.id = tableData.getIntField(0, int{});
		entry.description = tableData.getStringField(1, std::string{}.c_str());
		entry.minTameUpdateTime = tableData.getFloatField(2, float{});
		entry.maxTameUpdateTime = tableData.getFloatField(3, float{});
		entry.percentTameChance = tableData.getFloatField(4, float{});
		entry.tamability = tableData.getFloatField(5, float{});
		entry.elementType = tableData.getIntField(6, int{});
		entry.walkSpeed = tableData.getFloatField(7, float{});
		entry.runSpeed = tableData.getFloatField(8, float{});
		entry.sprintSpeed = tableData.getFloatField(9, float{});
		entry.idleTimeMin = tableData.getFloatField(10, float{});
		entry.idleTimeMax = tableData.getFloatField(11, float{});
		entry.eggLotId = tableData.getIntField(12, int{});
		entry.petForm = tableData.getIntField(13, int{});
		entry.imaginationDrainRate = tableData.getFloatField(14, float{});
		entry.AudioMetaEventSet = tableData.getStringField(15, std::string{}.c_str());
		entry.playerFlag = tableData.getIntField(16, int{});
		this->m_entries.push_back(entry);
		tableData.nextRow();
	}

	tableData.finalize();
}

CDPetComponentTable::~CDPetComponentTable() {
}

std::string CDPetComponentTable::GetName(void) const {
	return "PetComponent";
}

std::vector<CDPetComponent> CDPetComponentTable::Query(std::function<bool(CDPetComponent)> predicate) {
	std::vector<CDPetComponent> data = cpplinq::from(this->m_entries)
		>> cpplinq::where(predicate)
		>> cpplinq::to_vector();

	return data;
}

std::vector<CDPetComponent> CDPetComponentTable::GetEntries(void) const {
	return this->m_entries;
}
