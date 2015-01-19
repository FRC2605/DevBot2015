#ifndef SHS2605_DEVBOT_H
#define SHS2605_DEVBOT_H

#include <Hardware/Drive/MecanumDrive.h>
#include "WPILib.h"

#define JOYSTICK_DEADZONE 0.01
//#include "DSP/MagnitudeCurveFilter.h"

// Mates of states

#include "Hardware/Drive/Filters/MecanumVelocityProfile.h"

class DevBot : public IterativeRobot
{
public:
	
	DevBot ();
	~DevBot ();
	
	void TeleopInit ();
	void DisabledInit ();
	
	void TeleopPeriodic ();
	
	void ControllerDeadZone ( double & JoystickInput );
private:
	
	CANJaguar WheelFL;
	CANJaguar WheelFR;
	CANJaguar WheelRL;
	CANJaguar WheelRR;
	
	MecanumVelocityProfile VProfile;

	MecanumDrive Drive;
	
	Talon TestMotor;
	Counter TestCounter;

	Joystick StrafeStick;
	Joystick RotateStick;

	Talon Lift;
	

};

#define ROBOT_CLASS DevBot

#endif
