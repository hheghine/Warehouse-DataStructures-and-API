#ifndef IRON_HPP
# define IRON_HPP

# include "AMaterial.hpp"

class AMaterial;

class Iron : public AMaterial {
	public:
		Iron();
		~Iron();

		AMaterial*	clone() const;
};

#endif