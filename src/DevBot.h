#ifndef SHS2605_DEVBOT_H
#define SHS2605_DEVBOT_H

#include "WPILib.h"

#include "Hardware/DriveTrains/MecanumDrive.h"

class DevBot : public IterativeRobot
{
public:
	
	DevBot ();
	~DevBot ();
	
//	void AutonomousInit();
	void TeleopInit ();
	void DisabledInit ();
	
//	void AutonomousPeriodic();
	void TeleopPeriodic ();
	
	void ScaleCurve ( double & x , double & y );
	void ScaleCurve ( double & x );
	
private:
	
	CANJaguar WheelFL;
	CANJaguar WheelFR;
	CANJaguar WheelRL;
	CANJaguar WheelRR;
	
	MecanumDrive Drive;

	Talon TestMotor;
	Counter TestCounter;

	Joystick StrafeStick;
	Joystick RotateStick;
	
};

#define ROBOT_CLASS DevBot

#endif
