/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:50:37 by emansoor          #+#    #+#             */
/*   Updated: 2024/10/21 09:32:29 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

# include "Animal.hpp"

class Cat : public Animal {

	public:

		Cat();
		Cat(std::string type);
		Cat(const Cat &copy);
		~Cat();
		Cat&	operator=(const Cat &other);

		void		makeSound() const override;
		std::string	getType() const override;
		
};

#endif