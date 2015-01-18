#include "DevBot.h"
#include <cmath>


DevBot :: DevBot ():
	IterativeRobot (),
	WheelFL ( 22 ),
	WheelFR ( 23 ),
	WheelRL ( 21 ),
	WheelRR ( 20 ),
	VProfile ( 2.0 ),
	Drive ( & WheelFL, & WheelFR, & WheelRL, & WheelRR ),
	StrafeStick ( 0 ),
	RotateStick ( 1 ),
	Lift ( 1 )
	{
	
	Drive.SetInverted ( false, true, false, true );
	Drive.SetMotorScale ( 1000 );
	Drive.AddMagDirFilter ( & VProfile );


	WheelFL.SetSpeedMode ( CANJaguar :: QuadEncoder, 1000, 0.65, 0.017, 0.001 );
	WheelFR.SetSpeedMode ( CANJaguar :: QuadEncoder, 1000, 0.65, 0.017, 0.001 );
	WheelRL.SetSpeedMode ( CANJaguar :: QuadEncoder, 1000, 0.65, 0.017, 0.001 );
	WheelRR.SetSpeedMode ( CANJaguar :: QuadEncoder, 1000, 0.65, 0.017, 0.001 );
	
	//WheelFL.SetControlMode ( CANSpeedController :: ControlMode { 1 } );
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
	
	Drive.Enable ();
	
	WheelFL.EnableControl ();
	WheelFR.EnableControl ();
	WheelRL.EnableControl ();
	WheelRR.EnableControl ();
	
};

void DevBot :: TeleopPeriodic ()
{
	double X, Y, R,BLiftUp,BLiftDown;
	X = StrafeStick.GetX ();
	Y = StrafeStick.GetY ();
	//R = StrafeStick.GetZ ();
	R = RotateStick.GetX ();
	BLiftUp = RotateStick.GetRawButton ( 1 );
	BLiftDown = RotateStick.GetRawButton ( 2 );

	ControllerDeadZone ( X );
	ControllerDeadZone ( Y );
	ControllerDeadZone ( R );

	Drive.SetTranslation ( X , - Y );
	Drive.SetRotation ( R );
	

	if ( ( BLiftDown != 0 ) && ( BLiftUp == 0 ) )
		Lift.Set ( 1.0 );
	else if ( ( BLiftDown == 0 ) && ( BLiftUp != 0 ) )
		Lift.Set ( - 1.0 );
	else
		Lift.Set ( 0.0 );
	
	Drive.PushTransform ();
	
};

void DevBot :: DisabledInit ()
{
	
	WheelFL.DisableControl ();
	WheelFR.DisableControl ();
	WheelRL.DisableControl ();
	WheelRR.DisableControl ();
	
	Drive.Disable ();
	
};

void DevBot :: ControllerDeadZone ( double & JoystickInput )
{
	if ( std :: abs ( JoystickInput ) <= JOYSTICK_DEADZONE )
		JoystickInput = 0.0;
}

START_ROBOT_CLASS ( ROBOT_CLASS );
