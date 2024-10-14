/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:02:15 by emansoor          #+#    #+#             */
/*   Updated: 2024/10/14 17:46:56 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	int			zombie;

	try
	{
		Zombie	*Horde = new Zombie[N];
		if (Horde)
		{
			for (zombie = 0; zombie < N; zombie++)
				Horde[zombie].setName(name);
			return (Horde);
		}
	}
	catch(...)
	{
		std::cout << "Failed to allocate a horde of Zombies size " << N << std::endl;
	}
	return (nullptr);
}
