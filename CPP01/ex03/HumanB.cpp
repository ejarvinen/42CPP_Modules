/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:19:09 by emansoor          #+#    #+#             */
/*   Updated: 2024/10/07 16:38:57 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->_name = name;
};
HumanB::~HumanB(){};

void	HumanB::setWeapon(Weapon weapon)
{
	this->_weapon = weapon;
}

void	HumanB::attack()
{
	if (this->_weapon.getType().empty())
		std::cout << this->_name << " attacks with their bare hands" << std::endl;
	else
		std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}