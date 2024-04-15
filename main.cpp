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
	warehouse.removeMaterial("Iron", 666);

	std::cout << warehouse;


	delete iron;
}