#include "DevBot.h"

DevBot :: DevBot ():
	IterativeRobot (),
	WheelFL ( 21 ),
	WheelFR ( 23 ),
	WheelRL ( 22 ),
	WheelRR ( 20 ),
	Drive ( & WheelFL, & WheelFR, & WheelRL, & WheelRR ),
	StrafeStick ( 0 ),
	RotateStick ( 1 )
{	
	
	Drive.SetInverted ( false, true, false, true );
	Drive.SetMotorScale ( 1000 );
	
	WheelFL.SetSpeedMode ( CANJaguar :: QuadEncoder, 256, 0.95, 0.01, 0.005 );
	WheelFR.SetSpeedMode ( CANJaguar :: QuadEncoder, 256, 0.95, 0.01, 0.005 );
	WheelRL.SetSpeedMode ( CANJaguar :: QuadEncoder, 256, 0.95, 0.01, 0.005 );
	WheelRR.SetSpeedMode ( CANJaguar :: QuadEncoder, 256, 0.95, 0.01, 0.005 );
	
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
