#include "DevBot.h"
#include <cmath>


DevBot :: DevBot ():
	IterativeRobot (),
	WheelFL ( 2 ),
	WheelFR ( 1 ),
	WheelRL ( 3 ),
	WheelRR ( 4 ),
	VProfile ( 2.0 ),
	Drive ( & WheelFL, & WheelFR, & WheelRL, & WheelRR ),
	StrafeStick ( 0 ),
	RotateStick ( 1 ),
	Lift ( 5 )
	{
	
	Drive.SetInverted ( false, true, false, true );
	Drive.SetMotorScale ( 1 );
	Drive.AddMagDirFilter ( & VProfile );

	
	//WheelFL.SetControlMode ( CANSpeedController :: ControlMode { 1 } );
	WheelFL.Set ( 0 );
	WheelFR.Set ( 0 );
	WheelRL.Set ( 0 );
	WheelRR.Set ( 0 );
	
	
	
	
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
	bool BLiftUp, BLiftDown;
	BLiftUp = RotateStick.GetButtonState ( 1 );
	BLiftDown = RotateStick.GetButtonState ( 2 );

	Drive.SetTranslation ( StrafeStick.GetXAxis () , - StrafeStick.GetYAxis () );
	Drive.SetRotation ( StrafeStick.GetXAxis () );
	

	if ( ! BLiftDown && BLiftUp )
		Lift.Set ( 1.0 );
	else if ( BLiftDown && ! BLiftUp )
		Lift.Set ( - 1.0 );
	else
		Lift.Set ( 0.0 );
	
	Drive.PushTransform ();
	
};

void DevBot :: DisabledInit ()
{
	
	Drive.Disable ();
	
};


START_ROBOT_CLASS ( ROBOT_CLASS );
