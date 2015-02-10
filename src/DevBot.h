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

#include "Hardware/Drive/CANTalonPositionServo.h"

#include "Sensing/DIO/DIOSwitchLimit.h"

#include "DSInput/JoystickXYInput.h"

#include "Behaviors/BehaviorController.h"

#include "LinearSlide.h"

#include "JoystickMecanumDriveBehavior.h"

class DevBot : public IterativeRobot
{
public:
	
	DevBot ();
	~DevBot ();
	
	void TeleopInit ();
	void DisabledInit ();
	void TestInit ();
	
	void TeleopPeriodic ();
	void DisabledPeriodic ();
	void TestPeriodic ();
	
private:
	
	CANTalonConfiguration WheelConfig;
	
	MecanumVelocityProfile VProfile;
	
	CANTalonQuadDriveBase DriveBase;
	MecanumDriveTrain DriveTrain;
	
	Joystick StrafeStick;
	Joystick RotateStick;

	CANTalonPositionServo WinchServo;
	
	DigitalInput WinchLimitHigh;
	DigitalInput WinchLimitLow;
	DIOSwitchLimit WinchLimits;
	
	LinearSlide Winch;
	
	JoystickXYInput StrafeInput;
	JoystickXYInput RotationInput;
	
	BehaviorController Behaviors;
	
	JoystickMecanumDriveBehavior DriveBehavior;

};

#define ROBOT_CLASS DevBot

#endif
