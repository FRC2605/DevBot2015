#include "SmartJoystick.h"
#include <cmath>

SmartJoystick :: SmartJoystick ( int JoystickNumber, double Deadzone)
	: Joystick ( JoystickNumber ),
	  AxisDeadzone ( Deadzone )
{

}

float SmartJoystick :: GetXAxis ( bool WithDeadzone, double Deadzone)
{
	float X;
	X = this -> GetX ();

	if ( WithDeadzone )
	{
		if ( Deadzone == 0.0 )
			Deadzone = AxisDeadzone;
		CalcDeadzone ( X , Deadzone);
	}
	return X;
}

float SmartJoystick :: GetYAxis ( bool WithDeadzone, double Deadzone)
{
	float Y;
	Y = this -> GetY ();

	if ( WithDeadzone )
	{
		if ( Deadzone == 0.0 )
			Deadzone = AxisDeadzone;
		CalcDeadzone ( Y , Deadzone);
	}
	return Y;
}

float SmartJoystick :: GetZAxis ( bool WithDeadzone, double Deadzone)
{
	float Z;
	Z = this -> GetZ ();

	if ( WithDeadzone )
	{
		if ( Deadzone == 0.0 )
			Deadzone = AxisDeadzone;
		CalcDeadzone ( Z , Deadzone);
	}
	return Z;
}

bool SmartJoystick :: GetButtonState ( uint32_t ButtonNumber )
{
	double State;
	State = this -> GetRawButton ( ButtonNumber );

	if ( State == 0 )
		return true;
	else
		return false;
}

void SmartJoystick :: CalcDeadzone ( float & AxisIn, double & Deadzone )
{
	if ( abs ( AxisIn ) <= Deadzone )
		AxisIn = 0;
}
