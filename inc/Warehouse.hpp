#ifndef WAREHOUSE_HPP
# define WAREHOUSE_HPP

/*   COLOR CONSTANTS   */
# define WHT "\033[0;37m"
# define GRN "\033[0;32m"
# define CYN "\033[0;36m"
# define GRY "\033[0;90m"
# define RED "\033[0;31m"
# define YLW "\033[0;33m"

# define BWHT "\033[1;37m"
# define BGRN "\033[1;32m"
# define BCYN "\033[1;36m"
# define BGRY "\033[1;90m"

# define CRST "\033[0m"

/*    LIBRARIES    */
# include <iostream>
# include <exception>
# include <vector>
# include <string>
# include <map>

# include "AMaterial.hpp"


class AMaterial;

using map_iterator = std::map<std::string, AMaterial *>::iterator;
using map = std::map<std::string, AMaterial *>;

class Warehouse {
	private:
		map	warehouse;
	public:
		/* CONSTRUCTORS */
		Warehouse();
		~Warehouse();
		/* NO COPY OPTION */
		Warehouse(const Warehouse& rhs) = delete;
		Warehouse&	operator= (const Warehouse& rhs) = delete;
	public:
		/* EXCEPTION CLASS */
		class ExchangeException : public std::exception {
			public:
				const char*	what() const throw();
		};
	public:
		/* MATERIAL MANIPULATIONS */
		void	learnMaterial(AMaterial* material);
		void	addMaterial(const std::string& material, const size_t quantity);
		void	removeMaterial(const std::string& material, const size_t quantity);

		/* GETTERS */
		size_t	getMaterialQuantity(const std::string& material) const;
		size_t	getMaterialCapacity(const std::string& material) const;

		/* HELPER METHODS */
		bool		isKnownMaterial(const std::string& material) const;
		const map&	getMap() const;
		void		notifyUnknown() const;
};

std::ostream&	operator<<(std::ostream& out, const Warehouse& wh);
void			materialExchange(const std::string& material, Warehouse& from, Warehouse& to, size_t quantity);

#endif