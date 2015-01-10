#ifndef SHS2605_DEVBOT_H
#define SHS2605_DEVBOT_H

#include "WPILib.h"

#include "Hardware/DriveTrains/MecanumDrive.h"

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
	
	CANJaguar WheelFL;
	CANJaguar WheelFR;
	CANJaguar WheelRL;
	CANJaguar WHeelRR;
	
	MecanumDrive Drive;
	
	Joystick StrafeStick;
	Joystick RotateStick;
	
};

#define ROBOT_CLASS DevBot

#endif
