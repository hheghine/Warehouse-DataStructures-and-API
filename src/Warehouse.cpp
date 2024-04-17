#include "Warehouse.hpp"

Warehouse::Warehouse() {}

Warehouse::~Warehouse() {}

const char*	Warehouse::ExchangeException::what() const noexcept
{
	return ("[ warehouse exception ] impossible exchange");
}

const char*	Warehouse::MaterialException::what() const noexcept
{
	return ("[ warehouse exception ] invalid pointer");
}

void	Warehouse::learnMaterial(AMaterial* material)
{
	if (!material)
		throw Warehouse::MaterialException();
	if (warehouse.find(material->getName()) == warehouse.end())
		warehouse[material->getName()] = std::unique_ptr<AMaterial>(material->clone());
}

void	Warehouse::addMaterial(const std::string& material, const size_t quantity)
{
	if (warehouse.find(material) != warehouse.end())
	{
		warehouse[material]->addQuantity(quantity);
		notifyObservers();
	}
	else
		notifyUnknown();
}

void	Warehouse::removeMaterial(const std::string& material, const size_t quantity)
{
	if (warehouse.find(material) != warehouse.end())
	{
		warehouse[material]->reduceQuantity(quantity);
		if (getMaterialQuantity(material) == 0)
			forgetMaterial(material);
		notifyObservers();
	}
	else
		notifyUnknown();
}

void	Warehouse::forgetMaterial(const std::string& material)
{
	map_iterator it = warehouse.find(material);
	if (it != warehouse.end())
		warehouse.erase(it);
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
	return (warehouse.find(material) != warehouse.end());
}

void	Warehouse::notifyUnknown() const
{
	std::cout << YLW << " [ ⚠ warning ]" << CRST << "\t\tunknown material" << CRST << std::endl;
}

const Warehouse::map&	Warehouse::getMap() const
{
	return warehouse;
}

std::ostream&	operator<<(std::ostream& out, const Warehouse& wh)
{
	const Warehouse::map& warehouse = wh.getMap();

	for (auto const& it : warehouse)
	{
		out << BGRY << "\n+--------------------------------------------------------------------------------------+\n" << CRST \
		<< "Material name:\t\t" << BCYN << (it.second)->getName() << std::endl \
		<< CRST << "Description: \t\t" << BCYN << (it.second)->getDescription() << std::endl \
		<< CRST << "Icon: \t\t\t" << BCYN << (it.second)->getIcon() << std::endl \
		<< CRST << "Max capacity: \t\t" << BCYN << (it.second)->getMaxCapacity() << std::endl \
		<< CRST << "Total quantity: \t" << BCYN << (it.second)->getQuantity() << CRST << std::endl;
	}
	out << BGRY << "+--------------------------------------------------------------------------------------+\n\n" << CRST;
	return out;
}

void	materialExchange(const std::string& material, Warehouse& from, Warehouse& to, size_t quantity)
{
	size_t from_quantity = from.getMaterialQuantity(material);
	if (!from_quantity || from_quantity < quantity)
		throw Warehouse::ExchangeException();
	if (!to.isKnownMaterial(material))
		to.learnMaterial((from.getMap()).find(material)->second.get());
	size_t available = to.getMaterialCapacity(material) - to.getMaterialQuantity(material);
	if (available < quantity)
		std::cout << YLW << " [ ⚠ warning ]" << CRST << "\t\tavailable capacity: " << CYN << available << CRST << std::endl;
	else
	{
		from.removeMaterial(material, quantity);
		to.addMaterial(material, quantity);
	}
}

void	Warehouse::registerObserver(Observer* observer)
{
	observers.push_back(observer);
}

void	Warehouse::removeObserver(Observer* observer)
{
	observers.erase(std::remove_if(observers.begin(), observers.end(),
							[observer](Observer* o) { return o == observer; }),
						observers.end());
}

void	Warehouse::notifyObservers()
{
	for (Observer* observer : observers)
		observer->update(*this);
}