#include "Iron.hpp"

Iron::Iron()
	: AMaterial("Iron", \
		"This metal of legend, forged in the heart of stars, is the backbone of civilizations", \
		"Gleaming with untold potential, a symbol of power and progress", \
		999, \
		0)
{}

AMaterial*	Iron::clone() const
{
	return new Iron();
}