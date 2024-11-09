/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:30:56 by emansoor          #+#    #+#             */
/*   Updated: 2024/11/09 13:27:31 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_H
# define BASE_H

# include <cstdlib>
# include <iostream>

class Base {

	public:
	
		virtual ~Base();

};

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);

#endif