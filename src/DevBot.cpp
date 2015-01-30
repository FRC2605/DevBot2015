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
	Test.SetPID ( .4 ,0.0 , 7 );
	Test.SetCloseLoopRampRate(48);
	Test.SetFeedbackDevice ( CANTalon :: QuadEncoder);
	Test.SetSensorDirection( false );
	updateTimer.Start();



};

DevBot :: ~DevBot ()
{



};

void DevBot :: TeleopInit ()
{
	Test.SetPosition( 0 );
	Test.Set( 0 );
	Test.EnableControl ();


};

void DevBot :: TeleopPeriodic ()
{
	int encoderPos = Test.GetEncPosition();
	int encoderVel = Test.GetEncVel();

	int closedLoopError = Test.GetClosedLoopError();

	double outputV = Test.GetOutputVoltage();
	double busV = Test.GetBusVoltage();

	int SensorPos = Test.GetPosition();
	int SensorVel = Test.GetSpeed();

	//SmartDashboard :: PutNumber("Encoder Pos",encoderPos);

	//if( updateTimer.HasPeriodPassed( 1 ) )
	//{
		SmartDashboard :: PutNumber("Encoder Pos",encoderPos);
		SmartDashboard :: PutNumber("Encoder Vel",encoderVel);

		SmartDashboard :: PutNumber("Closed Loop Error" , closedLoopError);

		SmartDashboard :: PutNumber("Output Voltage", outputV);

		SmartDashboard :: PutNumber("Selected Sensor Pos", SensorPos );
		SmartDashboard :: PutNumber ("Selected Sensor Vel", SensorVel);
	//}

	Test.Set ( 15000 );

};

void DevBot :: DisabledInit()
{
	Test.SetPosition ( 0 );
	Test.Disable();
};

START_ROBOT_CLASS ( DevBot )
