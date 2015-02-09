#ifndef SHS2605_DEVBOT_H
#define SHS2605_DEVBOT_H

#include <WPILib.h>

#include "Hardware/Motors/CANTalonConfiguration.h"

#include "Hardware/Drive/CANTalonQuadDriveBase.h"
#include "Hardware/Drive/MecanumDriveTrain.h"

#include "Hardware/Drive/MecanumDrive.h"
#include "Hardware/Drive/Filters/MecanumVelocityProfile.h"
#include "Hardware/Drive/Filters/MecanumMagDirOrientationOffset.h"

#include "Hardware/Drive/Filters/MecanumVelocityProfile.h"

class DevBot : public IterativeRobot
{
public:
	
	DevBot ();
	~DevBot ();
	
	void TeleopInit ();
	void DisabledInit ();
	
	void TeleopPeriodic ();
	void DisabledPeriodic ();
	
private:
	
	CANTalonConfiguration WheelConfig;
	
	MecanumVelocityProfile VProfile;
	
	//SerialPort Nav6COM;
	//Nav6 Nav;
	//Nav6YawAngle YawReference;
	//MecanumMagDirOrientationOffset FieldOrientation;
	
	CANTalonQuadDriveBase DriveBase;
	MecanumDriveTrain DriveTrain;
	
	Joystick StrafeStick;
	Joystick RotateStick;

	Talon Lift;
	

};

#define ROBOT_CLASS DevBot

#endif
