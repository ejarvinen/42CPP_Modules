#include "Zombie.hpp"

Zombie	*newZombie(std::string name);

void	randomChump(std::string name);

int	main(void)
{
	Zombie	*allocatedZombie1;
	Zombie	*allocatedZombie2;

	allocatedZombie1 = newZombie("Albert");
	if (!allocatedZombie1)
		std::cout << "Whoopsie, allocating Albert failed" << std::endl;
	std::cout << "This is Albert the allocated Zombie announcing himself:" << std::endl;
	allocatedZombie1->announce();
	std::cout << "********************" << std::endl;
	std::cout << "This is Benedict the stack memory Zombie being called: " << std::endl;
	randomChump("Benedict");
	std::cout << "********************" << std::endl;
	allocatedZombie2 = newZombie("Clement");
	if (!allocatedZombie1)
		std::cout << "Whoopsie, allocating Clement failed" << std::endl;
	std::cout << "This is Clement the allocated Zombie announcing himself:" << std::endl;
	allocatedZombie2->announce();
	std::cout << "********************" << std::endl;
	std::cout << "This is Dalton the stack memory Zombie being called: " << std::endl;
	randomChump("Dalton");
	std::cout << "********************" << std::endl;
	if (allocatedZombie1)
		delete allocatedZombie1;
	if (allocatedZombie2)
		delete allocatedZombie2;
	return (0);
}
