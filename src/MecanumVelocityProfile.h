#ifndef DEVBOT_MECANUMVELOCITYPROFILE_H
#define DEVBOT_MECANUMVELOCITYPROFILE_H

#include "DSP/DSPFilter.h"

class MecanumVelocityProfile : public DSPFilter_2_2
{
public:

	MecanumVelocityProfile ( double Exponent );
	~MecanumVelocityProfile ();

	void Compute ( double Magnitude, double Direction );

	double ReadA ();
	double ReadB ();

	void Reset ();

private:

	double Exponent;
	double Magnitude;
	double Direction;

};

#endif
