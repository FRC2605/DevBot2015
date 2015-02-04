#ifndef SHS_ROBOT_H
#define SHS_ROBOT_H

#include <WPILib.h>

// See IUL for this header
#include "../Input/SmartJoystick.h"

class DevBot : public IterativeRobot
{
public:

	DevBot ();
	~DevBot ();

	void TeleopInit ();
	void TeleopPeriodic ();
	void OutputToSmartdashboard();
	void DisabledInit ();
private:
	Timer updateTimer;

	CANTalon Test;

	SmartJoystick Joy;

};

#define ROBOT_CLASS DevBot

#endif
