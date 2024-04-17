#include "Warehouse.hpp"
#include "Iron.hpp"
#include "Copper.hpp"
#include "Lumisteel.hpp"

int	main()
{
	Warehouse	warehouse;

	std::unique_ptr<Iron> iron = std::make_unique<Iron>();
	std::unique_ptr<Copper> copper = std::make_unique<Copper>();
	std::unique_ptr<Lumisteel> lumisteel = std::make_unique<Lumisteel>();

	std::unique_ptr<Observer> observer1 = std::make_unique<Observer>();
	std::unique_ptr<Observer> observer2 = std::make_unique<Observer>();

	warehouse.registerObserver(observer1.get());
	warehouse.registerObserver(observer2.get());

	warehouse.learnMaterial(iron.get());

	warehouse.addMaterial("Iron", 4);
	warehouse.addMaterial("Iron", 999);

	warehouse.addMaterial("blabla", 4);

	Warehouse other;
	std::unique_ptr<Observer> observer3 = std::make_unique<Observer>();

	other.registerObserver(observer3.get());

	other.learnMaterial(lumisteel.get());
	other.addMaterial("Lumisteel", 777);

	warehouse.removeObserver(observer2.get());

	try {
			materialExchange("Iron", warehouse, other, 998);
			materialExchange("Lumisteel", other, warehouse, 42);
		} catch (const std::exception& e) {
			std::cout << RED << e.what() << CRST << std::endl;
		}

	warehouse.learnMaterial(copper.get());
	warehouse.addMaterial("Copper", 78);
}