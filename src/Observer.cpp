#include "Observer.hpp"

int	Observer::id = 0;

Observer::Observer()
{
	id++;
	_id = id;
}

void	Observer::update(const Warehouse& wh)
{
	std::cout << BGRN << "\n\n\t\t\t***** OBSERVER " << _id << " *****" << CRST << std::endl;
	for (auto const& it : wh.getMap())
	{
		std::cout << BGRN << "+--------------------------------------------------------------------------------------+\n" << CRST \
		<< "Material name:\t\t" << BCYN << (it.second)->getName() << std::endl \
		<< CRST << "Description: \t\t" << BCYN << (it.second)->getDescription() << std::endl \
		<< CRST << "Icon: \t\t\t" << BCYN << (it.second)->getIcon() << std::endl \
		<< CRST << "Max capacity: \t\t" << BCYN << (it.second)->getMaxCapacity() << std::endl \
		<< CRST << "Total quantity: \t" << BCYN << (it.second)->getQuantity() << CRST << std::endl;
	}
	std::cout << BGRN << "+--------------------------------------------------------------------------------------+\n\n" << CRST;
}