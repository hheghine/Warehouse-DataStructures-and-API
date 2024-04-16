#ifndef LUMISTEEL_HPP
# define LUMISTEEL_HPP

# include "AMaterial.hpp"

class AMaterial;

class Lumisteel : public AMaterial {
	public:
		Lumisteel();
		~Lumisteel();

		AMaterial*	clone() const;
};

#endif