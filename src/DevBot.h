#ifndef SHS_ROBOT_H
#define SHS_ROBOT_H

#include <WPILib.h>
#include "SmartJoystick.h"

class DevBot : public IterativeRobot
{
public:

	DevBot ();
	~DevBot ();

	void TeleopInit ();
	void TeleopPeriodic ();

	void DisabledInit ();
private:
	Timer updateTimer;

	CANTalon Test;

	SmartJoystick Joy;

};

#endif
