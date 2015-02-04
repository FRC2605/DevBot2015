#include "DevBot.h"
#include <cmath>


#include <iostream>

DevBot :: DevBot ():
	IterativeRobot (),
	WheelFL ( 40 ),
	WheelFR ( 43 ),
	WheelRL ( 41 ),
	WheelRR ( 42 ),
	VProfile ( 2.0 ),
	Nav6COM ( 57600, SerialPort :: kOnboard ),
	Nav6 ( & Nav6COM, 20 ),
	YawReference ( & Nav6 ),
	FieldOrientation ( & YawReference ),
	Drive ( & WheelFL, & WheelFR, & WheelRL, & WheelRR ),
	StrafeStick ( 0 ),
	RotateStick ( 1 ),
	Lift ( 1 )
{	
	
	Drive.SetInverted ( false, true, false, true );
	Drive.SetMotorScale ( 7000 );
	Drive.AddMagDirFilter ( & VProfile );
	Drive.AddMagDirFilter ( & FieldOrientation );
	
	WheelFL.SetControlMode ( CANTalon :: kSpeed );
	WheelFR.SetControlMode ( CANTalon :: kSpeed );
	WheelRL.SetControlMode ( CANTalon :: kSpeed );
	WheelRR.SetControlMode ( CANTalon :: kSpeed );
	
	WheelFL.SetFeedbackDevice ( CANTalon :: QuadEncoder );
	WheelFR.SetFeedbackDevice ( CANTalon :: QuadEncoder );
	WheelRL.SetFeedbackDevice ( CANTalon :: QuadEncoder );
	WheelRR.SetFeedbackDevice ( CANTalon :: QuadEncoder );
	
	WheelFL.SetSensorDirection ( false );
	WheelFR.SetSensorDirection ( false );
	WheelRL.SetSensorDirection ( false );
	WheelRR.SetSensorDirection ( false );
	
	WheelFL.SetPID ( 0.2, 0.0, 0.0 );
	WheelFR.SetPID ( 0.2, 0.0, 0.0 );
	WheelRL.SetPID ( 0.2, 0.0, 0.0 );
	WheelRR.SetPID ( 0.2, 0.0, 0.0 );
	
	WheelFL.Set ( 0 );
	WheelFR.Set ( 0 );
	WheelRL.Set ( 0 );
	WheelRR.Set ( 0 );
	
	WheelFL.EnableControl ();
	WheelFR.EnableControl ();
	WheelRL.EnableControl ();
	WheelRR.EnableControl ();
	
};

DevBot :: ~DevBot ()
{
};

void DevBot :: TeleopInit ()
{
	
	Nav6.ZeroYaw ();
	
	FieldOrientation.CalibrateZero ();
	
	Drive.Enable ();
	
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

	Drive.SetTranslation ( X , - Y );
	Drive.SetRotation ( R );
	
	Drive.PushTransform ();
	
	if ( BLiftUp && ! BLiftDown )
		Lift.Set ( 1.0 );
	else if ( BLiftDown && ! BLiftUp )
		Lift.Set ( - 1.0 );
	else
		Lift.Set ( 0.0 );
	
};

void DevBot :: DisabledInit ()
{
	
	Drive.Disable ();
	
	Nav6.Restart ();

};

void DevBot :: DisabledPeriodic ()
{
	
	std :: cout << "Connected: " << ( Nav6.IsConnected () ? "Yes" : "No" ) << ", Yaw: " << Nav6.GetYaw () << "\n";
	
};

START_ROBOT_CLASS ( ROBOT_CLASS );
