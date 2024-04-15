#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "Warehouse.hpp"

class AMaterial {
	private:
		std::string	_name;
		std::string	_description;
		std::string	_icon;
		size_t		_max_capacity;
		size_t		_quantity;
	public:
		AMaterial() = delete;
		AMaterial(const std::string& name, const std::string& description, \
					const std::string& icon, const size_t capacity, const size_t quantity);
		AMaterial(const AMaterial& rhs);
		virtual ~AMaterial();

		AMaterial&	operator= (const AMaterial& rhs);

		const std::string&	getName() const;
		const std::string&	getDescription() const;
		const std::string&	getIcon() const;
		size_t				getMaxCapacity() const;
		size_t				getQuantity() const;

		void	addQuantity(const size_t quantity);
		void	reduceQuantity(const size_t quantity);

		virtual AMaterial*	clone() const = 0;
};

#endif