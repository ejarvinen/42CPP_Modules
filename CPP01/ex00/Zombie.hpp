#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <string>
# include <iostream>

class Zombie {
	
	private:

		std::string	_name;

	public:

		Zombie();
		~Zombie();
		
		void	announce(void);
		void	setName(std::string name);
};

#endif