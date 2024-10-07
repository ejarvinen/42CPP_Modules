/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:19:24 by emansoor          #+#    #+#             */
/*   Updated: 2024/10/07 16:40:29 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H

# include <string>
# include <iostream>
# include "Weapon.hpp"

class HumanA {

	private:

		Weapon		_weapon;
		std::string	_name;

	public:

		HumanA(std::string name, Weapon weapon);
		~HumanA();

		void	attack();
};

#endif