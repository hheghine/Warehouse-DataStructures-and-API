#ifndef WAREHOUSE_HPP
# define WAREHOUSE_HPP

/*    LIBRARIES    */
# include <unordered_map>
# include <exception>
# include <iostream>
# include <vector>
# include <string>
# include <memory>

/*   COLOR CONSTANTS   */
constexpr char WHT[] = "\033[0;37m";
constexpr char GRN[] = "\033[0;32m";
constexpr char CYN[] = "\033[0;36m";
constexpr char GRY[] = "\033[0;90m";
constexpr char RED[] = "\033[0;31m";
constexpr char YLW[] = "\033[0;33m";

constexpr char BWHT[] = "\033[1;37m";
constexpr char BGRN[] = "\033[1;32m";
constexpr char BCYN[] = "\033[1;36m";
constexpr char BGRY[] = "\033[1;90m";

constexpr char CRST[] = "\033[0m";


# include "AMaterial.hpp"

class AMaterial;


class Warehouse {
	public:
		using map_iterator = std::unordered_map<std::string, std::unique_ptr<AMaterial>>::iterator;
		using map_const_iterator = std::unordered_map<std::string, std::unique_ptr<AMaterial>>::const_iterator;
		using map = std::unordered_map<std::string, std::unique_ptr<AMaterial>>;
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
		/* EXCEPTION CLASSES */
		class MaterialException : public std::exception {
			public:
				const char*	what() const noexcept;
		};
		class ExchangeException : public std::exception {
			public:
				const char*	what() const noexcept;
		};
	public:
		/* MATERIAL MANIPULATIONS */
		void	learnMaterial(AMaterial* material);
		void	addMaterial(const std::string& material, const size_t quantity);
		void	removeMaterial(const std::string& material, const size_t quantity);
		void	forgetMaterial(const std::string& material);

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