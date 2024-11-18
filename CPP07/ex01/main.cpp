/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:59:32 by emansoor          #+#    #+#             */
/*   Updated: 2024/11/18 16:01:46 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

template <typename T, typename U, typename W> void    iter(T *address, U len, W *(func)(T param))
{
	U	index;

	if (address)
	{
		for (index = 0; index < len; index++)
			(func)(address[index]);
	}
}

int	increment(int num)
{
	return (num++);
}

int	main(void)
{
	int	*nums = new int[10];
	
	for (int index = 0; index < 10; index++)
		nums[index] = index;
	for (int index = 0; index < 10; index++)
		std::cout << "nums[" << index << "] = " << nums[index] << std::endl;
	iter(nums, 10, increment);
	for (int index = 0; index < 10; index++)
		std::cout << "nums[" << index << "] = " << nums[index] << std::endl;
	return (0);
}
