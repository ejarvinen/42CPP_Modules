/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:19:29 by emansoor          #+#    #+#             */
/*   Updated: 2024/10/07 16:40:45 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB {

	private:

		Weapon		_weapon;
		std::string	_name;

	public:

		HumanB(std::string name);
		~HumanB();

		void	attack();
		void	setWeapon(Weapon weapon);
};

#endif