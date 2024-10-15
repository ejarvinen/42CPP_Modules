/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:02:31 by emansoor          #+#    #+#             */
/*   Updated: 2024/10/15 10:33:36 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie		*horde;
	int			hordeSize;
	int			zombie;
	std::string	name;

	hordeSize = 10;
	name = "Edmund";
	horde = zombieHorde(hordeSize, name);
	if (!horde)
	{
		return (1);
	}
	std::cout << "Succesfully allocated an army of zombies!" << std::endl;
	std::cout << "Let's call all the " << hordeSize << " cadets to announce themselves:" << std::endl;
	for (zombie = 0; zombie < hordeSize; zombie++)
		horde[zombie].announce();
	std::cout << std::endl;
	std::cout << "Bye bye zombies:" << std::endl;
	delete[] horde;
	return (0);
}
