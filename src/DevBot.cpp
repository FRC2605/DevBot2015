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
	//Drive.SetMotorScale ( 1000 );
	Drive.AddMagDirFilter ( & VProfile );
	
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
	bool BLiftUp,BLiftDown;

	BLiftUp = RotateStick.GetButtonState ( 1 );
	BLiftDown = RotateStick.GetButtonState ( 2 );

	Drive.SetTranslation ( StrafeStick.GetXAxis() , - StrafeStick.GetYAxis() );
	Drive.SetRotation ( RotateStick.GetXAxis() );
	

	if ( BLiftDown &&  !BLiftUp )
		Lift.Set ( 1.0 );
	else if ( !BLiftDown  && BLiftUp )
		Lift.Set ( - 1.0 );
	else
		Lift.Set ( 0.0 );
	
	Drive.PushTransform ();
	
};

void DevBot :: DisabledInit ()
{
	
	Drive.Disable ();
	
};

START_ROBOT_CLASS ( DevBot );
