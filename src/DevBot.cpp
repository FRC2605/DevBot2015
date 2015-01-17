#include "DevBot.h"

static int lastCount;
static double lastTime;
static double integralError;

DevBot :: DevBot ():
	IterativeRobot (),
	WheelFL ( 21 ),
	WheelFR ( 23 ),
	WheelRL ( 22 ),
	WheelRR ( 20 ),
	Drive ( & WheelFL, & WheelFR, & WheelRL, & WheelRR ),
	TestMotor ( 0 ),
	TestCounter ( 0 ),
	StrafeStick ( 0 ),
	RotateStick ( 1 )
{

	Drive.SetInverted ( false, true, false, true );
	Drive.SetMotorScale ( 1000 );
	
	WheelFL.SetSpeedMode ( CANJaguar :: QuadEncoder, 256, 0.95, 0.01, 0.005 );
	WheelFR.SetSpeedMode ( CANJaguar :: QuadEncoder, 256, 0.95, 0.01, 0.005 );
	WheelRL.SetSpeedMode ( CANJaguar :: QuadEncoder, 256, 0.95, 0.01, 0.005 );
	WheelRR.SetSpeedMode ( CANJaguar :: QuadEncoder, 256, 0.95, 0.01, 0.005 );
	
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

void DevBot::TeleopInit()
{
	lastCount = 0;
	lastTime = GetTime();
	integralError = 0;
	TestCounter.Reset();
	TestCounter.SetMaxPeriod(0.1);
}

void DevBot::TeleopPeriodic()
{
//	TestMotor.Set(0.5);
	double commandVelocity = StrafeStick.GetRawAxis(1) * 25000.00;
	if (commandVelocity <= 0.0) {
		integralError = 0.0;
	}
	double kp = 0.00005;
	double ki = 0.00005;
	int count = TestCounter.Get();
	double time = GetTime();
	int sinceLastCount = count - lastCount;
	double sinceLastTime = time - lastTime;
	double velocity = sinceLastCount / sinceLastTime;
	double velocityError = commandVelocity - velocity;
	integralError += velocityError;
	SmartDashboard::PutNumber("velocity", velocity);
	SmartDashboard::PutNumber("since last count", sinceLastCount);
	SmartDashboard::PutNumber("commandVelocity", commandVelocity);
	double outputPWM = kp * (commandVelocity - velocity) + ki * integralError;
	outputPWM = outputPWM < 0.0 ? 0.0 : outputPWM;
	outputPWM = outputPWM > 1.0 ? 1.0 : outputPWM;
	TestMotor.Set(outputPWM);

	lastCount = count;
	lastTime = time;
}

//void DevBot :: TeleopInit ()
//{
//
//	Drive.Enable ();
//
//	WheelFL.EnableControl ();
//	WheelFR.EnableControl ();
//	WheelRL.EnableControl ();
//	WheelRR.EnableControl ();
//
//};
//
//void DevBot :: TeleopPeriodic ()
//{
//
//	Drive.SetTranslation ( StrafeStick.GetX () , - StrafeStick.GetY () );
//	Drive.SetRotation ( RotateStick.GetX () );
//
//	Drive.PushTransform ();
//
//};

void DevBot :: DisabledInit ()
{
	
	WheelFL.DisableControl ();
	WheelFR.DisableControl ();
	WheelRL.DisableControl ();
	WheelRR.DisableControl ();
	
	Drive.Disable ();
	
};

START_ROBOT_CLASS ( ROBOT_CLASS );
