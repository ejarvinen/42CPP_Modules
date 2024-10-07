/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:17:51 by emansoor          #+#    #+#             */
/*   Updated: 2024/10/07 16:43:25 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

# include <string>

class Weapon {

	private:

		std::string	_type;

	public:

		Weapon(std::string type);
		~Weapon();

		const std::string	&getType();
		void				setType(std::string);

};

#endif