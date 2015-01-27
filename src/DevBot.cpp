#include "DevBot.h"

DevBot :: DevBot ():
	IterativeRobot (),
	Test ( 40 ),
	Joy ( 0 , 0.04 )
{

	Test.SetControlMode ( CANTalon :: kSpeed );
	Test.Set( 0 );
	//Test.ConfigMaxOutputVoltage ( 12.0 );


	Test.SelectProfileSlot ( 0 );
	Test.SetIzone( 0 );
	Test.SetPID ( .4 ,0.0 , 7 ,0.003 );
	Test.SetCloseLoopRampRate(48);
	Test.SetFeedbackDevice ( CANTalon :: QuadEncoder);
	Test.SetSensorDirection( false );



};

DevBot :: ~DevBot ()
{



};

void DevBot :: TestInit ()
{
	Test.SetPosition( 0 );
	Test.Set( 0 );
	Test.EnableControl ();

};

void DevBot :: TestPeriodic ()
{

	Test.Set ( 15000 );

};

void DevBot :: DIsabledInit()
{
	Test.SetPosition ( 0 );
	Test.Disable();
};

START_ROBOT_CLASS ( DevBot )
