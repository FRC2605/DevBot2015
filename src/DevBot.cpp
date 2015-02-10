#include "DevBot.h"
#include <cmath>
#include <iostream>

DevBot :: DevBot ():
	IterativeRobot (),
	WheelConfig ( CANTalon :: kSpeed, CANTalonConfiguration :: kFeedbackType_QuadratureEncoder ),
	VProfile ( 2.0 ),
	DriveBase ( 40, 1, 43, 15, 41, 13, 42, 14, WheelConfig, 40.0, 120.0 ),
	DriveTrain ( & DriveBase ),
	StrafeStick ( 0 ),
	RotateStick ( 1 ),
	WinchServo ( 44, CANTalon :: QuadEncoder, 0 ),
	WinchLimitHigh ( 1 ),
	WinchLimitLow ( 0 ),
	WinchLimits ( & WinchLimitLow, & WinchLimitHigh ),
	Winch ( & WinchServo, & WinchLimits, 5000.0, 0.0 ),
	StrafeInput ( & StrafeStick ),
	RotationInput ( & RotateStick ),
	Behaviors (),
	DriveBehavior ( & DriveTrain, & StrafeInput, & RotationInput )
{
	
	StrafeInput.SetDeadband ( 0.1 );
	RotationInput.SetDeadband ( 0.1 );
	
	StrafeInput.SetInversion ( false, true );
	
	WinchServo.SetProfileSlot ( 0 );
	WinchServo.SetPIDF ( 0.7, 0.0, 0.3, 0.0 );
	
	WheelConfig.SetPIDF ( 0.2, 0.0, 0.0, 0.0 );
	WheelConfig.SetControlSlot ( 0 );
	WheelConfig.SetRampRates ( 0.0, 0.0 );
	WheelConfig.SetNeutralMode ( CANTalon :: kNeutralMode_Brake );
	
	DriveBase.SetWheelConfig ( WheelConfig );
	DriveBase.SetInversion ( false, true, false, true );
	
	DriveTrain.SetMotorScale ( 7000 );
	DriveTrain.AddMagDirFilter ( & VProfile );
	
	Behaviors.AddBehavior ( & DriveBehavior, JoystickMecanumDriveBehavior :: GetDefaultBehaviorID () );
	
	std :: cout << "sizeof ( DevBot ): " << sizeof ( DevBot ) << "\n";
	
};

DevBot :: ~DevBot ()
{
};

void DevBot :: TeleopInit ()
{
	
	DriveTrain.Enable ();
	
	Behaviors.StartBehavior ( JoystickMecanumDriveBehavior :: GetDefaultBehaviorID () );
	
};

void DevBot :: TeleopPeriodic ()
{
	
	Behaviors.Update ();
	
};

void DevBot :: TestInit ()
{
	
	Winch.Enable ();
	Winch.Home ();
	
};

void DevBot :: TestPeriodic ()
{
	
	Winch.Update ();
	
};

void DevBot :: DisabledInit ()
{
	
	Behaviors.StopBehavior ( JoystickMecanumDriveBehavior :: GetDefaultBehaviorID () );
	
	DriveTrain.Disable ();
	
	Winch.Disable ();
	
};

void DevBot :: DisabledPeriodic ()
{
	
	Behaviors.Update ();
	
};

START_ROBOT_CLASS ( ROBOT_CLASS );
