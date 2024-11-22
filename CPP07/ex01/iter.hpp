/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:54:55 by emansoor          #+#    #+#             */
/*   Updated: 2024/11/22 16:26:33 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
# define ITER_H

# include <iostream>

template <typename T>
void    iter(T *address, unsigned int len, void (*func)(T &param))
{
	unsigned int	index;

	if (address)
	{
		for (index = 0; index < len; index++)
			(*func)(address[index]);
	}
}

template <typename T>
void    iter(T *address, unsigned int len, void (*func)(const T &param))
{
	unsigned int	index;

	if (address)
	{
		for (index = 0; index < len; index++)
			(*func)(address[index]);
	}
}

template <typename T>
void	increment(T &member)
{
	member++;
}

template <typename T>
void	printMember(T &member)
{
	std::cout << member << std::endl;
}

#endif