#include "DevBot.h"
#include <cmath>

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

/*
void DevBot :: ScaleCurve ( double & x , double & y )
{
	double Magnitude , Direction;
	Magnitude = sqrt ( pow ( x , 2 ) + pow ( y , 2 ) );
	Direction = atan2 ( x , y);
	Magnitude = pow ( Magnitude * .01 , 2 );
	y = sin ( Direction ) * Magnitude;
	x = cos ( Direction ) * Magnitude;
}

void DevBot :: ScaleCurve ( double & x ) {
	x = pow ( x * .01 , 2 );
}*/

START_ROBOT_CLASS ( ROBOT_CLASS );
