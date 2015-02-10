#include "DevBot.h"
#include <cmath>


#include <iostream>

DevBot :: DevBot ():
	IterativeRobot (),
	WheelConfig ( CANTalon :: kSpeed, CANTalonConfiguration :: kFeedbackType_QuadratureEncoder ),
	VProfile ( 2.0 ),
	//Nav6COM ( 57600, SerialPort :: kOnboard ),
	//Nav ( & Nav6COM ),
	//YawReference ( & Nav6 ),
	//FieldOrientation ( & YawReference ),
	DriveBase ( 40, 1, 43, 15, 41, 13, 42, 14, WheelConfig, 40.0, 120.0 ),
	DriveTrain ( & DriveBase ),
	StrafeStick ( 0 ),
	RotateStick ( 1 ),
	WinchServo ( 44, CANTalon :: QuadEncoder, 0 ),
	WinchLimitHigh ( 1 ),
	WinchLimitLow ( 0 ),
	WinchLimits ( & WinchLimitLow, & WinchLimitHigh ),
	Winch ( & WinchServo, & WinchLimits, 1000.0, 0.0 )
{
	
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
	
};

DevBot :: ~DevBot ()
{
};

void DevBot :: TeleopInit ()
{
	
	DriveTrain.Enable ();
	
	//Winch.Enable ();
	
};

void DevBot :: TeleopPeriodic ()
{
	
	double X;
	double Y;
	double R;
	
	X = StrafeStick.GetX ();
	Y = StrafeStick.GetY ();
	
	R = RotateStick.GetX ();

	DriveTrain.SetTranslation ( X , - Y );
	DriveTrain.SetRotation ( R );
	
	DriveTrain.PushTransform ();
	
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
	
	DriveTrain.Disable ();
	
	Winch.Disable ();

};

void DevBot :: DisabledPeriodic ()
{
	
	//std :: cout << "Connected: " << ( Nav6.IsConnected () ? "Yes" : "No" ) << ", Yaw: " << Nav6.GetYaw () << "\n";
	
};

START_ROBOT_CLASS ( ROBOT_CLASS );
