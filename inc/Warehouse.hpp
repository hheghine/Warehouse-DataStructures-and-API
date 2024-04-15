#ifndef WAREHOUSE_HPP
# define WAREHOUSE_HPP

/*   color constants   */
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

# include <iostream>
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
		Warehouse();
		Warehouse(const Warehouse& rhs);
		~Warehouse();

		Warehouse&	operator= (const Warehouse& rhs);

		void	learnMaterial(AMaterial* material);
		void	addMaterial(const std::string& material, const size_t quantity);
		void	removeMaterial(const std::string& material, const size_t quantity);

		const map&	getMap() const;

		void	notifyWarning() const;
};

std::ostream&	operator<<(std::ostream& out, const Warehouse& wh);

#endif