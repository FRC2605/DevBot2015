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
	Lift ( 1 )
{	
	
	WheelConfig.SetPIDF ( 0.2, 0.0, 0.0, 0.0 );
	WheelConfig.SetControlSlot ( 0 );
	WheelConfig.SetRampRates ( 0.0, 0.0 );
	WheelConfig.SetNeutralMode ( CANTalon :: kNeutralMode_Brake );
	
	DriveBase.SetWheelConfig ( WheelConfig );
	DriveBase.SetInversion ( false, true, false, true );
	
	DriveTrain.SetMotorScale ( 7000 );
	DriveTrain.AddMagDirFilter ( & VProfile );
	//DriveTrain.AddMagDirFilter ( & FieldOrientation );
	
};

DevBot :: ~DevBot ()
{
};

void DevBot :: TeleopInit ()
{
	
	//Nav6.ZeroYaw ();
	
	//FieldOrientation.CalibrateZero ();
	
	DriveTrain.Enable ();
	
};

void DevBot :: TeleopPeriodic ()
{
	
	double X;
	double Y;
	double R;
	
	bool BLiftUp;
	bool BLiftDown;
	
	X = StrafeStick.GetX ();
	Y = StrafeStick.GetY ();
	
	R = RotateStick.GetX ();
	BLiftUp = RotateStick.GetRawButton ( 1 );
	BLiftDown = RotateStick.GetRawButton ( 2 );

	DriveTrain.SetTranslation ( X , - Y );
	DriveTrain.SetRotation ( R );
	
	DriveTrain.PushTransform ();
	
	if ( BLiftUp && ! BLiftDown )
		Lift.Set ( 1.0 );
	else if ( BLiftDown && ! BLiftUp )
		Lift.Set ( - 1.0 );
	else
		Lift.Set ( 0.0 );
	
};

void DevBot :: DisabledInit ()
{
	
	DriveTrain.Disable ();
	
	//Nav6.Restart ();

};

void DevBot :: DisabledPeriodic ()
{
	
	//std :: cout << "Connected: " << ( Nav6.IsConnected () ? "Yes" : "No" ) << ", Yaw: " << Nav6.GetYaw () << "\n";
	
};

START_ROBOT_CLASS ( ROBOT_CLASS );
