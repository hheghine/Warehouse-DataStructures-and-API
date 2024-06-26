#ifndef COPPER_HPP
# define COPPER_HPP

# include "AMaterial.hpp"

class AMaterial;

class Copper : public AMaterial {
	public:
		Copper();
		~Copper() = default;

		AMaterial*	clone() const;
};

#endif