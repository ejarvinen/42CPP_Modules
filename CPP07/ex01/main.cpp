/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:59:32 by emansoor          #+#    #+#             */
/*   Updated: 2024/11/18 17:12:07 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

template <typename T, typename W>
void    iter(T *address, unsigned int len, W (*func)(T &param))
{
	unsigned int	index;

	if (address)
	{
		for (index = 0; index < len; index++)
			(*func)(address[index]);
	}
}

void	increment(int &num)
{
	num++;
}

int	main(void)
{
	{
		int	*nums = new int[10];
		
		for (int index = 0; index < 10; index++)
			nums[index] = index;
		for (int index = 0; index < 10; index++)
			std::cout << "nums[" << index << "] = " << nums[index] << std::endl;
		iter(nums, 10, increment);
		for (int index = 0; index < 10; index++)
			std::cout << "nums[" << index << "] = " << nums[index] << std::endl;
		delete[] nums;
	}
	return (0);
}
