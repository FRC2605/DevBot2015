#include "DevBot.h"

DevBot :: DevBot ():
	IterativeRobot (),
	Test ( 40 ),
	Joy ( 0 , 0.04 )
{

	Test.SetControlMode ( CANTalon :: kPosition );

	//Test.ConfigMaxOutputVoltage ( 12.0 );


	Test.SelectProfileSlot ( 0 );
	Test.SetIzone( 0 );
	Test.SetPID ( 1 ,0.0 , 0 ,0.000 );
	Test.SetCloseLoopRampRate(48);
	Test.SetFeedbackDevice ( CANTalon :: QuadEncoder);
	Test.SetSensorDirection( false );



};

DevBot :: ~DevBot ()
{



};

void DevBot :: TestInit ()
{
	Test.SetPosition(0);
	Test.Set( 0 );
	Test.EnableControl ();

};

void DevBot :: TestPeriodic ()
{

	Test.Set ( 0 );

};

void DisabledInit ()
{



};

START_ROBOT_CLASS ( DevBot )
