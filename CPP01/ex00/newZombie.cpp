/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:02:49 by emansoor          #+#    #+#             */
/*   Updated: 2024/10/14 17:38:48 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*newZombie(std::string name)
{
	try
	{
		Zombie	*newZombie = new Zombie;
		if (newZombie)
		{
			newZombie->setName(name);
			return (newZombie);
		}
	}
	catch(...)
	{
		std::cout << "Failed to allocate a Zombie" << std::endl;
	}
	return (nullptr);
}
