/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:59:32 by emansoor          #+#    #+#             */
/*   Updated: 2024/11/19 10:27:24 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

// template <typename T, typename W>
// void    iter(T *address, unsigned int len, W (*func)(T &param))
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
	{
		int	*nums = new int[10];
		
		for (int index = 0; index < 10; index++)
			nums[index] = index;
		iter(nums, 10, printMember);
		for (int index = 0; index < 10; index++)
			std::cout << "nums[" << index << "] = " << nums[index] << std::endl;
		iter(nums, 10, increment);
		std::cout << std::endl;
		for (int index = 0; index < 10; index++)
			std::cout << "nums[" << index << "] = " << nums[index] << std::endl;
		delete[] nums;
	}
	std::cout << std::endl;
	{
		std::string	fruits[5] = {"apple", "banana", "coconut", "durian", "elderberry"};
		std::string	*fruitPtr = &fruits[5];
		
		iter(fruitPtr, 5, printMember);
		iter(fruitPtr, 5, increment);
	}
	return (0);
}
