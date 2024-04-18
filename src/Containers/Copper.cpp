#include "Copper.hpp"

Copper::Copper()
	: AMaterial("Copper", \
		"It whispers of ancient alchemies and modern marvels", \
		"Reflecting the light with a promise of innovation and beauty", \
		999, \
		0)
{}

AMaterial*	Copper::clone() const
{
	return new Copper();
}