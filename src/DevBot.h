#ifndef SHS2605_DEVBOT_H
#define SHS2605_DEVBOT_H

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
	
//	void AutonomousInit();
	void TeleopInit ();
	void DisabledInit ();
	
//	void AutonomousPeriodic();
	void TeleopPeriodic ();
	
	void ControllerDeadZone ( double & JoystickInput );
private:
	
	CANJaguar WheelFL;
	CANJaguar WheelFR;
	CANJaguar WheelRL;
	CANJaguar WheelRR;
	
	MecanumDrive Drive;
<<<<<<< HEAD

=======
	
>>>>>>> 79c729a1db98e846d2872e6c7a2240fd6a95648b
	Talon TestMotor;
	Counter TestCounter;

	Joystick StrafeStick;
	Joystick RotateStick;
	

};

#define ROBOT_CLASS DevBot

#endif
