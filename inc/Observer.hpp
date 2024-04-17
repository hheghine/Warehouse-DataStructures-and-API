#ifndef OBSERVER_HPP
# define OBSERVER_HPP

# include "Warehouse.hpp"

class Warehouse;

class Observer {
	private:
		static int	id;
		int			_id;
	public:
		Observer();

		void	update (const Warehouse& wh);
};

#endif