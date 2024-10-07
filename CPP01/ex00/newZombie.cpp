#include "Zombie.hpp"

Zombie	*newZombie(std::string name)
{
	Zombie	*newZombie = new Zombie;

	if (!newZombie)
		return (nullptr);
	newZombie->setName(name);
	return (newZombie);
}
