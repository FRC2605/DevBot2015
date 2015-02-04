#ifndef SHS2605_DEVBOT_H
#define SHS2605_DEVBOT_H

#include <WPILib.h>

#include "Hardware/Drive/MecanumDrive.h"
#include "Hardware/Drive/Filters/MecanumVelocityProfile.h"
#include "Hardware/Drive/Filters/MecanumMagDirOrientationOffset.h"

#include "Sensing/Nav6/IMU.h"
#include "Sensing/Nav6/Nav6YawAngle.h"

#include "Hardware/Motors/CANJaguarConfiguration.h"

class DevBot : public IterativeRobot
{
public:
	
	DevBot ();
	~DevBot ();
	
	void TeleopInit ();
	void DisabledInit ();
	
	void TeleopPeriodic ();
	void DisabledPeriodic ();
	
	void ScaleCurve ( double & x , double & y );
	void ScaleCurve ( double & x );
	
private:
	
	CANTalon WheelFL;
	CANTalon WheelFR;
	CANTalon WheelRL;
	CANTalon WheelRR;
	
	CANJaguarConfiguration WheelConfig;
	
	MecanumVelocityProfile VProfile;
	
	SerialPort Nav6COM;
	IMU Nav6;
	Nav6YawAngle YawReference;
	MecanumMagDirOrientationOffset FieldOrientation;

	MecanumDrive Drive;
	
	Joystick StrafeStick;
	Joystick RotateStick;

	Talon Lift;
	
};

#define ROBOT_CLASS DevBot

#endif
