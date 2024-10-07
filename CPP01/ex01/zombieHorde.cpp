/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:02:15 by emansoor          #+#    #+#             */
/*   Updated: 2024/10/07 14:02:18 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
