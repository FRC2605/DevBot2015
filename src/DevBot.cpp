#include "DevBot.h"
#include "Math.h"

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
	Drive.SetTranslation ( RightStick.GetX (), - RightStick.GetY () );
	Drive.SetRotation ( RightStick.GetZ () * 0.6 );
	
	Drive.PushTransform ();
	
};

void DevBot :: DisabledInit ()
{
	
	Drive.Disable ();
	
};

START_ROBOT_CLASS ( ROBOT_CLASS );
