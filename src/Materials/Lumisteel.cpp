#include "Lumisteel.hpp"

Lumisteel::Lumisteel()
	: AMaterial("Lumisteel", \
	"Rumored to be forged from the stars themselves, as light as a feather but stronger than steel", \
	"Radiating a soft, ethereal light", \
	999, \
	0)
{}

Lumisteel::~Lumisteel() {}

AMaterial*	Lumisteel::clone() const
{
	return new Lumisteel();
}