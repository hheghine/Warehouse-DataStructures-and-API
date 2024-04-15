#include "Warehouse.hpp"

Warehouse::Warehouse() {}

Warehouse::~Warehouse() {
	for (map_iterator it = warehouse.begin(); it != warehouse.end(); ++it)
		delete it->second;
	warehouse.clear();
}

Warehouse::Warehouse(const Warehouse& rhs)
{
	warehouse = rhs.warehouse;
}

Warehouse&	Warehouse::operator= (const Warehouse& rhs)
{
	warehouse = rhs.warehouse;
	return *this;
}

void	Warehouse::learnMaterial(AMaterial* material)
{
	if (warehouse.find(material->getName()) == warehouse.end())
		warehouse[material->getName()] = material->clone();
}

void	Warehouse::addMaterial(const std::string& material, const size_t quantity)
{
	if (warehouse.find(material) != warehouse.end())
		warehouse[material]->addQuantity(quantity);
	else
		notifyWarning();
}

void	Warehouse::removeMaterial(const std::string& material, const size_t quantity)
{
	if (warehouse.find(material) != warehouse.end())
		warehouse[material]->reduceQuantity(quantity);
	else
		notifyWarning();
}

void	Warehouse::notifyWarning() const
{
	std::cout << YLW " [ ⚠ warning ] unknown material" CRST << std::endl;
}

const map&	Warehouse::getMap() const
{
	return warehouse;
}

std::ostream&	operator<<(std::ostream& out, const Warehouse& wh)
{
	map warehouse = wh.getMap();
	for (map_iterator it = warehouse.begin(); it != warehouse.end(); ++it)
	{
		out << BGRY "\n+--------------------------------------------------------------------------------------+\n" CRST \
		<< "Material name:\t\t" BCYN << (it->second)->getName() << std::endl \
		<< CRST "Description: \t\t" BCYN << (it->second)->getDescription() << std::endl \
		<< CRST "Icon: \t\t\t" BCYN << (it->second)->getIcon() << std::endl \
		<< CRST "Max capacity: \t\t" BCYN << (it->second)->getMaxCapacity() << std::endl \
		<< CRST "Total quantity: \t" BCYN << (it->second)->getQuantity() << CRST << std::endl;
	}
	out << BGRY "+--------------------------------------------------------------------------------------+\n" CRST;
	return out;
}