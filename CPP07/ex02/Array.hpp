/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:42:59 by emansoor          #+#    #+#             */
/*   Updated: 2024/11/19 13:11:25 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

# include <iostream>

template <class T>
class Array {
	
	private:

		T *a;

	public:
	
		Array();
		Array(unsigned int n);
		Array(Array const &copy);
		~Array();
		Array &operator=(Array const &other);
		
		unsigned int	size();
	
};

# include "Array.tpp"
#endif