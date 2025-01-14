#pragma once
#include "CDTable.h"

//Generated by xmlDb2dDatabaseGenerator on 2022-03-04 00:23:33.467578
//DO NOT EDIT THIS FILE MANUALLY!

struct CDVehiclePhysics {
	int id;
	std::string name;
	std::string hkxFilename;
	float fGravityScale;
	float fMass;
	float fChassisFriction;
	float fMaxSpeed;
	float fEngineTorque;
	float fBrakeFrontTorque;
	float fBrakeRearTorque;
	float fBrakeMinInputToBlock;
	float fBrakeMinTimeToBlock;
	float fSteeringMaxAngle;
	float fSteeringSpeedLimitForMaxAngle;
	float fSteeringMinAngle;
	float fFwdBias;
	float fFrontTireFriction;
	float fRearTireFriction;
	float fFrontTireFrictionSlide;
	float fRearTireFrictionSlide;
	float fFrontTireSlipAngle;
	float fRearTireSlipAngle;
	float fWheelWidth;
	float fWheelRadius;
	float fWheelMass;
	float fReorientPitchStrength;
	float fReorientRollStrength;
	float fSuspensionLength;
	float fSuspensionStrength;
	float fSuspensionDampingCompression;
	float fSuspensionDampingRelaxation;
	int iChassisCollisionGroup;
	float fNormalSpinDamping;
	float fCollisionSpinDamping;
	float fCollisionThreshold;
	float fTorqueRollFactor;
	float fTorquePitchFactor;
	float fTorqueYawFactor;
	float fInertiaRoll;
	float fInertiaPitch;
	float fInertiaYaw;
	float fExtraTorqueFactor;
	float fCenterOfMassFwd;
	float fCenterOfMassUp;
	float fCenterOfMassRight;
	float fWheelHardpointFrontFwd;
	float fWheelHardpointFrontUp;
	float fWheelHardpointFrontRight;
	float fWheelHardpointRearFwd;
	float fWheelHardpointRearUp;
	float fWheelHardpointRearRight;
	float fInputTurnSpeed;
	float fInputDeadTurnBackSpeed;
	float fInputAccelSpeed;
	float fInputDeadAccelDownSpeed;
	float fInputDecelSpeed;
	float fInputDeadDecelDownSpeed;
	float fInputSlopeChangePointX;
	float fInputInitialSlope;
	float fInputDeadZone;
	float fAeroAirDensity;
	float fAeroFrontalArea;
	float fAeroDragCoefficient;
	float fAeroLiftCoefficient;
	float fAeroExtraGravity;
	float fBoostTopSpeed;
	float fBoostCostPerSecond;
	float fBoostAccelerateChange;
	float fBoostDampingChange;
	float fPowerslideNeutralAngle;
	float fPowerslideTorqueStrength;
	int iPowerslideNumTorqueApplications;
	float fImaginationTankSize;
	float fSkillCost;
	float fWreckSpeedBase;
	float fWreckSpeedPercent;
	float fWreckMinAngle;
	std::string AudioEventEngine;
	std::string AudioEventSkid;
	std::string AudioEventLightHit;
	float AudioSpeedThresholdLightHit;
	float AudioTimeoutLightHit;
	std::string AudioEventHeavyHit;
	float AudioSpeedThresholdHeavyHit;
	float AudioTimeoutHeavyHit;
	std::string AudioEventStart;
	std::string AudioEventTreadConcrete;
	std::string AudioEventTreadSand;
	std::string AudioEventTreadWood;
	std::string AudioEventTreadDirt;
	std::string AudioEventTreadPlastic;
	std::string AudioEventTreadGrass;
	std::string AudioEventTreadGravel;
	std::string AudioEventTreadMud;
	std::string AudioEventTreadWater;
	std::string AudioEventTreadSnow;
	std::string AudioEventTreadIce;
	std::string AudioEventTreadMetal;
	std::string AudioEventTreadLeaves;
	std::string AudioEventLightLand;
	float AudioAirtimeForLightLand;
	std::string AudioEventHeavyLand;
	float AudioAirtimeForHeavyLand;
};

class CDVehiclePhysicsTable : public CDTable {
private:
	std::vector<CDVehiclePhysics> m_entries;
public:
	CDVehiclePhysicsTable();
	~CDVehiclePhysicsTable();
	std::string GetName(void) const override;

std::vector<CDVehiclePhysics> Query(std::function<bool(CDVehiclePhysics)> predicate);
	std::vector<CDVehiclePhysics> GetEntries(void) const;
};
