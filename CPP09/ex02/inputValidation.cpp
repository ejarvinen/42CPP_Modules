/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputValidation.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 17:49:36 by emansoor          #+#    #+#             */
/*   Updated: 2024/12/25 17:50:15 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool	PmergeMe::isAllDigits(std::string num)
{
	for (int index = 0; num[index]; index++)
	{
		if (std::isdigit(num[index]) == 0)
			return (false);
	}
	return (true);
}

int	PmergeMe::checkArgs(char **argv)
{
	int index;
	int	num;

	for (index = 1; argv[index]; index++)
	{
		if (isAllDigits(argv[index]))
		{
			try
			{
				num = std::stoi(argv[index]);
			}
			catch (const std::exception& e)
			{
				return (1);
			}
			_sortedVec.push_back(num);
			_sortedList.push_back(num);
		}
		else
			return (1);
	}
	_size = index - 1;
	_unsorted = argv;
	return (0);
}
