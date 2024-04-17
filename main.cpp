#include "Warehouse.hpp"
#include "Iron.hpp"
#include "Copper.hpp"
#include "Lumisteel.hpp"

int	main() {
	Warehouse	warehouse;

	Iron* iron = new Iron();
	Copper* copper = new Copper();
	Lumisteel* lumisteel = new Lumisteel();

	warehouse.learnMaterial(iron);

	warehouse.addMaterial("Iron", 4);
	warehouse.addMaterial("Iron", 999);
	warehouse.addMaterial("Iron", 999);

	warehouse.addMaterial("blabla", 4);

	// warehouse.removeMaterial("Iron", 666);

	std::cout << warehouse;

	Warehouse other;

	other.learnMaterial(copper);
	other.addMaterial("Copper", 78);

	Warehouse third;

	std::cout << CYN << "\ntesting an invalid pointer..." << CRST << std::endl;
	try {
		third.learnMaterial(nullptr);
	} catch (const std::exception& e) {
		std::cout << RED << e.what() << CRST << std::endl;
	}
	std::cout << std::endl;

	third.learnMaterial(lumisteel);
	third.addMaterial("Lumisteel", 777);

	try {
		materialExchange("Iron", warehouse, other, 998);
		materialExchange("Copper", other, warehouse, 42);
		materialExchange("Lumisteel", third, warehouse, 777);
	} catch (const std::exception& e) {
		std::cout << RED << e.what() << CRST << std::endl;
	}

	std::cout << BGRN << "\nwarehouse:" << CRST << std::endl;
	std::cout << warehouse;
	std::cout << BGRN << "\nother:" << CRST << std::endl;
	std::cout << other;
	std::cout << BGRN << "\nthird:" << CRST << std::endl;
	std::cout << third;


	delete iron;
	delete copper;
	delete lumisteel;
}