/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:00:47 by emansoor          #+#    #+#             */
/*   Updated: 2024/10/21 12:18:06 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_H
# define WRONGCAT_H

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

	public:

		WrongCat();
		WrongCat(std::string type);
		WrongCat(const WrongCat &copy);
		~WrongCat();
		WrongCat&	operator=(const WrongCat &other);

		void	makeSound() const;
		
};

#endif