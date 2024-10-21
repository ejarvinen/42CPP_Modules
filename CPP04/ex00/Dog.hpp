/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:50:45 by emansoor          #+#    #+#             */
/*   Updated: 2024/10/21 12:16:41 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

# include "Animal.hpp"

class Dog : public Animal {

	public:

		Dog();
		Dog(std::string type);
		Dog(const Dog &copy);
		~Dog();
		Dog&	operator=(const Dog &other);

		void	makeSound() const override;
		
};

#endif