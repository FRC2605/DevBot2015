#include "DevBot.h"

DevBot :: DevBot ():
	IterativeRobot (),
	WheelFL ( 1 ),
	WheelFR ( 2 ),
	WheelRL ( 0 ),
	WheelRR ( 3 ),
	Drive ( & WheelFL, & WheelFR, & WheelRL, & WheelRR ),
	LeftStick ( 0 ),
	RightStick ( 1 )
{	
	
	Drive.SetInverted ( false, true, false, true );
	
};

DevBot :: ~DevBot ()
{
};

void DevBot :: TeleopInit ()
{
	
	Drive.Enable ();
	
};

void DevBot :: TeleopPeriodic ()
{
	double x , y , z;
	x = LeftStick.GetX ();
	y = LeftStick.GetY ();
	z = RightStick.GetX ();

	//ScaleCurve ( x, y );
	//ScaleCurve ( z );

	Drive.SetTranslation ( x , - y );
	Drive.SetRotation ( z * 0.6 );
	
	Drive.PushTransform ();
	
};

void DevBot :: DisabledInit ()
{
	
	Drive.Disable ();
	
};

START_ROBOT_CLASS ( ROBOT_CLASS );
