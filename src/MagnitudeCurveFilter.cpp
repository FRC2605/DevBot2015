#include "MagnitudeCurveFilter.h"
#include <cmath>

MagnitudeCurveFilter :: MagnitudeCurveFilter ()
{

}

MagnitudeCurveFilter :: ~MagnitudeCurveFilter () 
{

}

MagnitudeCurveFilter :: void Compute ( double FeedA, double FeedB )
{
	Magnitude = sqrt ( pow ( FeedA, 2 ) + pow ( FeedB, 2 ) );
	Direction = atan2 ( x, y);
	Magnitude = pow ( Magnitude, 2 );
}

MagnitudeCurveFilter ::	double ReadA ()
{
	return Magnitude;
}

MagnitudeCurveFilter ::	double ReadB ()
{
	return Direction;
}

MagnitudeCurveFilter ::	void Reset ()
{
	Magnitude = 0;
	Direction = 0;
}