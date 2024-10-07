#include "Zombie.hpp"

Zombie::Zombie(){};

Zombie::~Zombie()
{
	std::cout << "Deconstructor for zombie " << this->_name << " called" << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
