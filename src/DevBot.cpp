#include "DevBot.h"

DevBot :: DevBot ():
	IterativeRobot (),
	WheelFL ( 21 ),
	WheelFR ( 23 ),
	WheelRL ( 22 ),
	WheelRR ( 20 ),
	VProfile ( 2.0 ),
	Drive ( & WheelFL, & WheelFR, & WheelRL, & WheelRR ),
	StrafeStick ( 0 ),
	RotateStick ( 1 ),
	Lift ( 0 )
	{
	
	Drive.SetInverted ( false, true, true, true );
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

	Drive.SetTranslation ( StrafeStick.GetX () , - StrafeStick.GetY () );
	Drive.SetRotation ( RotateStick.GetX () );
	
	if ( ( StrafeStick.GetRawButton ( 2 ) != 0 ) && ( StrafeStick.GetRawButton ( 3 ) == 0 ) )
		Lift.Set ( 1.0 );
	else if ( ( StrafeStick.GetRawButton ( 2 ) == 0 ) && ( StrafeStick.GetRawButton ( 3 ) != 0 ) )
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

START_ROBOT_CLASS ( ROBOT_CLASS );
