#ifndef SHS2605_LINEARSLIDE_H
#define SHS2605_LINEARSLIDE_H

#include "Motion/IPositionDrive.h"
#include "Sensing/IMotionLimit.h"

class LinearSlide
{
public:
	
	LinearSlide ( IPositionDrive * Motor, IMotionLimit * Limit );
	
private:
	
	IPositionDrive * Motor;
	
	IMotionLimit * Limit;
	
	double HighLimit;
	double LowLimit;
	
};

#endif
