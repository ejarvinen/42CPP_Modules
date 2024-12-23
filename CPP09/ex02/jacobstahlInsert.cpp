/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jacobstahlInsert.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:03:27 by emansoor          #+#    #+#             */
/*   Updated: 2024/12/23 16:20:14 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

double PmergeMe::jacobstahl(double n)
{
    if (n == 0)
        return (0);
    if (n == 1)
        return (1);
    return (jacobstahl(n - 1) + 2 * jacobstahl(n - 2));
}

void	PmergeMe::initJacobstahl(void)
{
	int		index = 0;
	double	jNum = 0;

	jNum = jacobstahl(index);
	while (jNum <= (double)_size)
	{
		_jNums.push_back(jNum);
		index++;
		jNum = jacobstahl(index);
	}
	_jNums.push_back(jNum);
}

int	PmergeMe::getjNumIndex(double pendSize)
{
	int	index = 0;
	std::deque<double>::iterator it = _jNums.begin();
	std::deque<double>::iterator end = _jNums.end();

	while (it != end && *it <= pendSize)
	{
		index++;
		std::advance(it, 1);
	}
	return (index);
}

void	PmergeMe::updateJIndexes(std::vector<int> &pendIndexes, int index, double increment)
{
	std::vector<int>::iterator it = pendIndexes.begin();
	std::vector<int>::iterator end = pendIndexes.end();

	while (it != end && *it != index)
	{
		*it = (double)*it + increment;
		std::advance(it, 1);
	}
}

void	PmergeMe::jacobstahlInsert(std::vector<int> &main, std::vector<int> &pend, std::vector<int> &pendIndexes, double N)
{
	double	jNum;
	double	prevjNum;
	int		startLevel = 3;
	int		elemSize = N / 2;
	int		pendIndex;
	int		index;
	int		maxIndex = getjNumIndex(pendIndexes.size());

	std::vector<int>::iterator m;
	std::vector<int>::iterator p;

	while (startLevel <= maxIndex)
	{
		jNum = _jNums.at(startLevel);
		prevjNum = _jNums.at(startLevel - 1);
		if (((jNum - 1) * elemSize - 1) > pend.size() - 1)
		{
			jNum = pend.size() / elemSize + 1;
		}
		while (jNum > prevjNum)
		{
			pendIndex = (jNum - 1) * elemSize - 1; // index for pend elements
			m = main.begin();
			p = pend.begin();
			index = elemSize - 1;
			while (index < pendIndexes.at(jNum - 2) && (std::size_t)index < main.size() && index != -1)
			{
				if (main.at(index) > pend.at(pendIndex))
				{
					if (index != (elemSize - 1))
					{
						std::advance(m, index - (elemSize - 1));
					}
					std::advance(p, pendIndex - (elemSize - 1)); // do these need to be protected?
					main.insert(m, p, p + elemSize);
					updateJIndexes(pendIndexes, pendIndex, elemSize);
					index = -1 - (index + elemSize);
				}
				index = index + elemSize;
			}
			if (index > 0)
			{
				std::advance(m, pendIndexes.at(jNum - 2)); // does this need to be protected
				main.insert(m, p, p + elemSize);
			}
			jNum--;
		}
		startLevel++;
	}
}

/* std::cout << "Jacobstahl numbers:" << std::endl;
	std::deque<double>::iterator it = _jNums.begin();
	std::deque<double>::iterator end = _jNums.end();
	while (it != end)
	{
		std::cout << *it << std::endl;
		std::advance(it, 1);
	} */