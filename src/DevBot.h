#ifndef SHS2605_DEVBOT_H
#define SHS2605_DEVBOT_H

#include <Hardware/Drive/MecanumDrive.h>
#include <Hardware/Drive/Filters/MecanumVelocityProfile.h>
#include <Hardware/Drive/Filters/RotationFilter.h>
#include "WPILib.h"
#include "SmartJoystick.h"

#define JOYSTICK_DEADZONE 0.01
//#include "DSP/MagnitudeCurveFilter.h"

// Mates of states

class DevBot : public IterativeRobot
{
public:
	
	DevBot ();
	~DevBot ();
	
	void TeleopInit ();
	void DisabledInit ();
	
	void TeleopPeriodic ();

private:
	
	CANTalon WheelFL;
	CANTalon WheelFR;
	CANTalon WheelRL;
	CANTalon WheelRR;
	
	MecanumVelocityProfile VProfile;
	RotationFilter RProfile;

	MecanumDrive Drive;
	
	SmartJoystick StrafeStick;
	SmartJoystick RotateStick;

	Talon Lift;
	

};

#define ROBOT_CLASS DevBot

#endif
