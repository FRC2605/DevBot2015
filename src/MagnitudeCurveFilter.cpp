#include "MagnitudeCurveFilter.h"
#include <cmath>

MagnitudeCurveFilter :: MagnitudeCurveFilter ()
{
	Magnitude = 0;
	Direction = 0;
}

MagnitudeCurveFilter :: ~MagnitudeCurveFilter () 
{
}

void MagnitudeCurveFilter :: Compute ( double FeedA, double FeedB )
{
	Magnitude = sqrt ( pow ( FeedA, 2 ) + pow ( FeedB, 2 ) );
	Direction = atan2 ( FeedA, FeedB );
	Magnitude = pow ( Magnitude, 2 );
}

double MagnitudeCurveFilter :: ReadA ()
{
	return Magnitude;
}

double MagnitudeCurveFilter :: ReadB ()
{
	return Direction;
}

void MagnitudeCurveFilter :: Reset ()
{
	Magnitude = 0;
	Direction = 0;
}
