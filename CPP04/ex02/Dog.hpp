/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:50:45 by emansoor          #+#    #+#             */
/*   Updated: 2024/10/20 14:00:48 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {

	private:

		Brain	*ideas;

	public:

		Dog();
		Dog(std::string type);
		Dog(const Dog &copy);
		~Dog();
		Dog&	operator=(const Dog &other);

		void			makeSound() const override;
		std::string		getType() const override;
		void			printAddress();
};


#endif