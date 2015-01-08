#ifndef SHS2605_DEVBOT_H
#define SHS2605_DEVBOT_H

#include "WPILib.h"

#include "MecanumDrive.h"

class DevBot : public IterativeRobot
{
public:
	
	DevBot ();
	~DevBot ();
	
	void TeleopInit ();
	void DisabledInit ();
	
	void TeleopPeriodic ();

	void ScaleCurve ( double & x , double & y );
	void ScaleCurve ( double & x );
private:
	
	Talon WheelFL;
	Talon WheelFR;
	Talon WheelRL;
	Talon WheelRR;
	
	MecanumDrive Drive;
	
	Joystick LeftStick;
	Joystick RightStick;
	
};

#define ROBOT_CLASS DevBot

#endif
