#include "DevBot.h"
#include <cmath>

DevBot :: DevBot ():
	IterativeRobot (),
	WheelFL ( 1 ),
	WheelFR ( 2 ),
	WheelRL ( 0 ),
	WheelRR ( 3 ),
	Drive ( & WheelFL, & WheelFR, & WheelRL, & WheelRR ),
	StrafeStick ( 0 ),
	RotateStick ( 1 )
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

	Drive.SetTranslation ( StrafeStick.GetX () , - StrafeStick.GetY () );
	Drive.SetRotation ( RotateStick.GetX () );
	
	Drive.PushTransform ();
	
};

void DevBot :: DisabledInit ()
{
	
	Drive.Disable ();
	
};

START_ROBOT_CLASS ( ROBOT_CLASS );
