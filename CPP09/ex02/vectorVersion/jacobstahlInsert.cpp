/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jacobstahlInsert.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:03:27 by emansoor          #+#    #+#             */
/*   Updated: 2024/12/26 19:38:07 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../PmergeMe.hpp"

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

void	PmergeMe::jacobstahlInsert(std::vector<int> &main, std::vector<int> &pend,
std::vector<int> &pendIndexes, double N)
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
			pendIndex = (jNum - 1) * elemSize - 1;
			m = main.begin();
			p = pend.begin();
			index = elemSize - 1;
			while (index > -1 && index <= pendIndexes.at(jNum - 2)
				&& (std::size_t)index < main.size())
			{
				if (main.at(index) > pend.at(pendIndex))
				{
					if (index != (elemSize - 1))
					{
						std::advance(m, index - (elemSize - 1));
					}
					std::advance(p, pendIndex - (elemSize - 1));
					main.insert(m, p, p + elemSize);
					updateIndexes(pendIndexes, pendIndexes.at(jNum - 2), elemSize, index);
					index = -1 - (index + elemSize);
				}
				index = index + elemSize;
			}
			if (index > 0)
			{
				std::advance(m, pendIndexes.at(jNum - 2));
				std::advance(p, pendIndex - (elemSize - 1));
				main.insert(m, p, p + elemSize);
				updateIndexes(pendIndexes, pendIndexes.at(jNum - 2), elemSize, index);
			}
			jNum--;
		}
		startLevel++;
	}
}
