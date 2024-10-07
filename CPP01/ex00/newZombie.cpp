#include "Zombie.hpp"

Zombie	*newZombie(std::string name)
{
	Zombie	*newZombie = new Zombie;

	if (!newZombie)
		return (NULL);
	newZombie->setName(name);
	return (newZombie);
}
