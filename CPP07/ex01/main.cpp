/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:59:32 by emansoor          #+#    #+#             */
/*   Updated: 2024/11/19 10:40:24 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

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
void	increment(T &member)
{
	member++;
}

template <typename T>
void	printMember(T &member)
{
	std::cout << member << std::endl;
}

int	main(void)
{
	int	nums[] = {1, 2, 3, 4, 5};
	std::string	fruits[] = {"apple", "banana", "coconut", "durian", "elderberry"};
	
	iter(nums, 5, printMember);
	iter(nums, 5, increment);
	std::cout << std::endl;
	iter(nums, 5, printMember);
	
	std::cout << std::endl;
	
	iter(fruits, 5, printMember);

	return (0);
}
