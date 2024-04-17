#include "AMaterial.hpp"

AMaterial::AMaterial(const std::string& name, const std::string& description, \
	const std::string& icon, const size_t capacity, const size_t quantity)
	: _name(name)
	, _description(description)
	, _icon(icon)
	, _max_capacity(capacity)
	, _quantity(quantity)
{}

const std::string&	AMaterial::getName() const
{
	return _name;
}

const std::string&	AMaterial::getDescription() const
{
	return _description;
}

const std::string&	AMaterial::getIcon() const
{
	return _icon;
}

size_t	AMaterial::getMaxCapacity() const
{
	return _max_capacity;
}

size_t	AMaterial::getQuantity() const
{
	return _quantity;
}

void	AMaterial::addQuantity(const size_t quantity)
{
	size_t added = _max_capacity - _quantity >= quantity ? quantity : _max_capacity - _quantity;
	_quantity += added;
	std::cout << _name << " material: " << GRN << "+" << added << CRST \
	<< "\ttotal quantity: " << CYN << _quantity << CRST << std::endl;
}

void	AMaterial::reduceQuantity(const size_t quantity)
{
	size_t reduced = _quantity >= quantity ? quantity : 999;
	_quantity -= reduced;
	std::cout << _name << " material: " << RED << "-" << reduced << CRST \
	<< "\ttotal quantity: " << CYN << _quantity << CRST << std::endl;
}