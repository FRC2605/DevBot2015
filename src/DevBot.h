#ifndef SHS_ROBOT_H
#define SHS_ROBOT_H

#include <WPILib.h>
#include "SmartJoystick.h"

class DevBot : public IterativeRobot
{
public:

	DevBot ();
	~DevBot ();

	void TestInit ();
	void TestPeriodic ();

	void DIsabledInit ();

private:

	CANTalon Test;

	SmartJoystick Joy;

};

#endif
