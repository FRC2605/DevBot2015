#include "DevBot.h"

DevBot :: DevBot ():
	IterativeRobot (),
	WheelFL ( 22 ),
	WheelFR ( 23 ),
	WheelRL ( 21 ),
	WheelRR ( 20 ),
	VProfile ( 2.0 ),
	Drive ( & WheelFL, & WheelFR, & WheelRL, & WheelRR ),
	StrafeStick ( 0, 0.05 ),
	RotateStick ( 1, 0.05 ),
	Lift ( 1 )
	{
	
	Drive.SetInverted ( false, true, false, true );
	Drive.SetMotorScale ( 1000 );
	Drive.AddMagDirFilter ( & VProfile );


	WheelFL.SetSpeedMode ( CANJaguar :: QuadEncoder, 1000, 0.65, 0.017, 0.001 );
	WheelFR.SetSpeedMode ( CANJaguar :: QuadEncoder, 1000, 0.65, 0.017, 0.001 );
	WheelRL.SetSpeedMode ( CANJaguar :: QuadEncoder, 1000, 0.65, 0.017, 0.001 );
	WheelRR.SetSpeedMode ( CANJaguar :: QuadEncoder, 1000, 0.65, 0.017, 0.001 );
	
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
	bool BLiftUp, BLiftDown;
	//X = StrafeStick.GetXAxis ();
	//Y = StrafeStick.GetYAxis ();
	//R = RotateStick.GetXAxis();
	BLiftUp = RotateStick.GetButtonState ( 1 );
	BLiftDown = RotateStick.GetButtonState ( 2 );

	Drive.SetTranslation ( StrafeStick.GetXAxis () , - StrafeStick.GetYAxis() );
	Drive.SetRotation ( RotateStick.GetXAxis() );
	

	if ( BLiftDown && BLiftUp )
		Lift.Set ( 1.0 );
	else if ( BLiftDown && BLiftUp )
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
