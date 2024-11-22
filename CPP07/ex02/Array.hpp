/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:42:59 by emansoor          #+#    #+#             */
/*   Updated: 2024/11/22 16:35:58 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

# include <iostream>

template <class T>
class Array {
	
	private:

		T 				*_a;
		unsigned int	_size;
		

	public:
	
		Array();
		Array(unsigned int n);
		Array(Array const &copy);
		~Array();
		Array &operator=(Array const &other);
		
		T				&operator[](unsigned int index);
		T				&operator[](unsigned int index) const;
		unsigned int	size();
		unsigned int	size() const;
	
};

# include "Array.tpp"
#endif