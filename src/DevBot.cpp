#include "DevBot.h"

DevBot :: DevBot ():
	IterativeRobot (),
	WheelFL ( 21 ),
	WheelFR ( 23 ),
	WheelRL ( 22 ),
	WheelRR ( 20 ),
	Drive ( & WheelFL, & WheelFR, & WheelRL, & WheelRR ),
	StrafeStick ( 0 ),
	RotateStick ( 1 ),
	Lift ( 0 )
{	
	
	Drive.SetInverted ( false, true, true, true );
	Drive.SetMotorScale ( 1000 );
	
	WheelFL.SetSpeedMode ( CANJaguar :: QuadEncoder, 1000, 0.4, 0.00, 0.00 );
	WheelFR.SetSpeedMode ( CANJaguar :: QuadEncoder, 1000, 0.4, 0.00, 0.00 );
	WheelRL.SetSpeedMode ( CANJaguar :: QuadEncoder, 1000, 0.4, 0.00, 0.00 );
	WheelRR.SetSpeedMode ( CANJaguar :: QuadEncoder, 1000, 0.4, 0.00, 0.00 );
	
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

	if ( RotateStick.GetRawButton ( 2 ) != 0 && RotateStick.GetRawButton( 3 ) != 0)
	{}
	else if ( RotateStick.GetRawButton ( 2 ) == 0 )
	{
		Lift.Set ( 1 );
	}
	else if ( RotateStick.GetRawButton ( 3 ) == 0 )
	{
		Lift.Set ( -1 );
	}
	else
	{
		Lift.Set ( 0 );
	}
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
