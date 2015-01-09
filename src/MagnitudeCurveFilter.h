##ifndef SHS2605_MAGNITUDECURVEFILTER_H
#define SHS2605_MAGNITUDECURVEFILTER_H

#include <cmath>
#include "LARUL.h"

class MagnitudeCurveFilter : public DSPFilter_2_2
{
public:
	MagnitudeCurveFilter();
	~MagnitudeCurveFilter();

	void Compute ( double FeedA, double FeedB );
	double ReadA ();
	double ReadB ();
	void Reset ();
private:
	double Magnitude;
	double Direction;
	
};
#endif