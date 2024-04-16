#include "Warehouse.hpp"

Warehouse::Warehouse() {}

Warehouse::~Warehouse() {
	for (map_iterator it = warehouse.begin(); it != warehouse.end(); ++it)
		delete it->second;
	warehouse.clear();
}

const char*	Warehouse::ExchangeException::what() const throw()
{
	return ("[ warehouse exception ] impossible exchange");
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
		notifyUnknown();
}

void	Warehouse::removeMaterial(const std::string& material, const size_t quantity)
{
	if (warehouse.find(material) != warehouse.end())
		warehouse[material]->reduceQuantity(quantity);
	else
		notifyUnknown();
}

size_t	Warehouse::getMaterialQuantity(const std::string& material) const
{
	return warehouse.find(material)->second->getQuantity();
}

size_t	Warehouse::getMaterialCapacity(const std::string& material) const
{
	return warehouse.find(material)->second->getMaxCapacity();
}

bool	Warehouse::isKnownMaterial(const std::string& material) const
{
	if (warehouse.find(material) == warehouse.end())
		return false;
	return true;
}

void	Warehouse::notifyUnknown() const
{
	std::cout << YLW " [ ⚠ warning ]" CRST "\t\tunknown material" CRST << std::endl;
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
	out << BGRY "+--------------------------------------------------------------------------------------+\n\n" CRST;
	return out;
}

void	materialExchange(const std::string& material, Warehouse& from, Warehouse& to, size_t quantity)
{
	size_t from_quantity = from.getMaterialQuantity(material);
	if (!from_quantity || from_quantity < quantity)
		throw Warehouse::ExchangeException();
	if (!to.isKnownMaterial(material))
		to.learnMaterial((from.getMap()).find(material)->second);
	size_t available = to.getMaterialCapacity(material) - to.getMaterialQuantity(material);
	if (available < quantity)
	{
		std::cout << YLW " [ ⚠ warning ]" CRST "\t\tavailable capacity: " CYN << available << CRST << std::endl;
	}
	else
	{
		from.removeMaterial(material, quantity);
		to.addMaterial(material, quantity);
	}
}