#ifndef SHS2605_LINEARSLIDE_H
#define SHS2605_LINEARSLIDE_H

#include "Motion/IPositionDrive.h"
#include "Sensing/IMotionLimit.h"

#include "Timing/TimedIncrementer.h"

#include "Hardware/HWSystem.h"

class LinearSlide : public HWSystem
{
public:
	
	LinearSlide ( IPositionDrive * Motor, IMotionLimit * Limit, double HomingSpeed, double Initial, double LowLimit = 0, double HighLimit = 0 );
	LinearSlide ( IPositionDrive * Motor, double Initial, double LowLimit, double HighLimit );
	~LinearSlide ();
	
	void TargetPosition ( double Position );
	void RunVelocity ( double Velocity );
	void HomeLow ();
	void HomeHigh ();
	void Home ();
	
	bool IsHoming ();
	bool TargetReached ( double Tolerance );
	
	double GetPosition ();
	
	void Update ();
	
	void Disable ();
	void Enable ();
	
	bool GetEnabled ();
	
private:
	
	typedef enum
	{
		
		kMode_Velocity,
		kMode_Position,
		kMode_HomeLow,
		kMode_HomeHigh,
		kMode_HomeLowHigh
		
	} Mode;
	
	IPositionDrive * Motor;
	
	IMotionLimit * Limit;
	
	double LowLimit;
	double HighLimit;
	
	TimedIncrementer Targeter;
	
	bool Enabled;
	
	Mode State;
	
	double HomingSpeed;
	
};

#endif
