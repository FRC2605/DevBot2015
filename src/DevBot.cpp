#include "DevBot.h"
#include <cmath>


DevBot :: DevBot ():
	IterativeRobot (),
	WheelFL ( 41 ),
	WheelFR ( 43 ),
	WheelRL ( 40 ),
	WheelRR ( 42 ),
	VProfile ( 2.0 ),
	Drive ( & WheelFL, & WheelRL, & WheelFR, & WheelRR ),
	StrafeStick ( 0 ),
	RotateStick ( 1 ),
	Lift ( 1 )
	{
	
	//Drive.SetInverted ( false, false, false, false );
	WheelFL.SetControlMode ( CANTalon :: kPercentVbus);
	WheelFR.SetControlMode ( CANTalon :: kPercentVbus);
	WheelRL.SetControlMode ( CANTalon :: kPercentVbus);
	WheelRR.SetControlMode ( CANTalon :: kPercentVbus);

	Drive.SetInvertedMotor ( RobotDrive :: kFrontLeftMotor, true);
	Drive.SetInvertedMotor ( RobotDrive :: kRearLeftMotor, true);
	//Drive.SetMotorScale ( 1000 );
	//Drive.AddMagDirFilter ( & VProfile );
	
};

DevBot :: ~DevBot ()
{
};

void DevBot :: TeleopInit ()
{
	
	//Drive.Enable ();
	
};

void DevBot :: TeleopPeriodic ()
{
	bool BLiftUp,BLiftDown;

	BLiftUp = RotateStick.GetButtonState ( 1 );
	BLiftDown = RotateStick.GetButtonState ( 2 );

	//Drive.SetTranslation ( StrafeStick.GetX() , - StrafeStick.GetY() );
	//Drive.SetRotation ( RotateStick.GetX() );
	Drive.MecanumDrive_Cartesian (   StrafeStick.GetY() , - StrafeStick.GetX() , RotateStick.GetX() );

	if ( BLiftDown &&  !BLiftUp )
		Lift.Set ( 1.0 );
	else if ( !BLiftDown  && BLiftUp )
		Lift.Set ( - 1.0 );
	else
		Lift.Set ( 0.0 );
	
	//Drive.PushTransform ();
	
};

void DevBot :: DisabledInit ()
{
	
	//Drive.Disable ();
	
};

START_ROBOT_CLASS ( DevBot );
