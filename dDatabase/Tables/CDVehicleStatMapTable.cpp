#include "CDVehicleStatMapTable.h"
//Generated by xmlDb2dDatabaseGenerator on 2022-03-04 00:23:33.486777
//DO NOT EDIT THIS FILE MANUALLY!

CDVehicleStatMapTable::CDVehicleStatMapTable() {
	unsigned int size = 0;
	auto tableSize = CDClientDatabase::ExecuteQuery("SELECT COUNT(*) FROM VehicleStatMap");
		while (!tableSize.eof()) {
		size = tableSize.getIntField(0, 0);
		tableSize.nextRow();
	}

	tableSize.finalize();
	this->m_entries.reserve(size);

	auto tableData = CDClientDatabase::ExecuteQuery("SELECT * FROM VehicleStatMap");
	while (!tableData.eof()) {
		CDVehicleStatMap entry;
		entry.id = tableData.getIntField(0, int{});
		entry.ModuleStat = tableData.getStringField(1, std::string{}.c_str());
		entry.HavokStat = tableData.getStringField(2, std::string{}.c_str());
		entry.HavokChangePerModuleStat = tableData.getFloatField(3, float{});
		this->m_entries.push_back(entry);
		tableData.nextRow();
	}

	tableData.finalize();
}

CDVehicleStatMapTable::~CDVehicleStatMapTable() {
}

std::string CDVehicleStatMapTable::GetName(void) const {
	return "VehicleStatMap";
}

std::vector<CDVehicleStatMap> CDVehicleStatMapTable::Query(std::function<bool(CDVehicleStatMap)> predicate) {
	std::vector<CDVehicleStatMap> data = cpplinq::from(this->m_entries)
		>> cpplinq::where(predicate)
		>> cpplinq::to_vector();

	return data;
}

std::vector<CDVehicleStatMap> CDVehicleStatMapTable::GetEntries(void) const {
	return this->m_entries;
}
