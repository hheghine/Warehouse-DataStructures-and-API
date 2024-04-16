#include "Warehouse.hpp"
#include "Iron.hpp"

int	main() {
	Warehouse	warehouse;
	Iron* iron = new Iron();

	warehouse.learnMaterial(iron);

	warehouse.addMaterial("Iron", 4);
	warehouse.addMaterial("Iron", 999);
	warehouse.addMaterial("Iron", 999);

	warehouse.addMaterial("blabla", 4);

	// warehouse.removeMaterial("Iron", 666);

	std::cout << warehouse;

	Warehouse other;

	other.learnMaterial(iron);
	other.addMaterial("Iron", 2);

	try {
		materialExchange("Iron", warehouse, other, 998);
	} catch (const std::exception& e) {
		std::cout << RED << e.what() << CRST << std::endl;
	}

	std::cout << warehouse;
	std::cout << other;


	delete iron;
}