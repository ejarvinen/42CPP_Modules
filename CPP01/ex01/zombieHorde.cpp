#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	int			zombie;

	if (N <= 0 || N > 1024)
	{
		std::cout << "Invalid size N" << std::endl;
		return (nullptr);
	}
	Zombie	*Horde = new Zombie[N];
	if (!Horde)
		return (nullptr);
	for (zombie = 0; zombie < N; zombie++)
		Horde[zombie].setName(name);
	return (Horde);
}
