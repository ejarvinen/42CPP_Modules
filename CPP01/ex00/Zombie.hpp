/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:03:02 by emansoor          #+#    #+#             */
/*   Updated: 2024/10/07 14:03:11 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif