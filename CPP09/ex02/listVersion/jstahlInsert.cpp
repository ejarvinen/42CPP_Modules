/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jstahlInsert.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:03:27 by emansoor          #+#    #+#             */
/*   Updated: 2024/12/26 19:33:16 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../PmergeMe.hpp"

void	PmergeMe::jstahlInsert(std::list<int> &main, std::list<int> &pend,
std::list<int> &pendIndexes, double N)
{
	double	jNum;
	double	prevjNum;
	int		startLevel = 3;
	int		elemSize = N / 2;
	int		pendIndex;
	int		index;
	int		maxIndex = getjNumIndex(pendIndexes.size());

	std::list<int>::iterator m;
	std::list<int>::iterator p;
	std::list<int>::iterator pBegin;
	std::list<int>::iterator pIndex;

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
			pBegin = pend.begin();
			std::advance(p, pendIndex);
			pIndex = pendIndexes.begin();
			std::advance(pIndex, jNum - 2);
			index = elemSize - 1;
			std::advance(m, index);
			while (index > -1 && index <= *pIndex && (std::size_t)index < main.size())
			{
				if (*m > *p)
				{
					std::advance(m, (-1) * (elemSize - 1));
					std::advance(pBegin, pendIndex - (elemSize - 1));
					std::advance(p, 1);
					main.insert(m, pBegin, p);
					updateIndexes(pendIndexes, *pIndex, elemSize, index);
					index = -1 - (index + elemSize);
				}
				index = index + elemSize;
				std::advance(m, elemSize);
			}
			if (index > 0)
			{
				std::advance(m, (-1) * (elemSize - 1));
				std::advance(pBegin, pendIndex - (elemSize - 1));
				std::advance(p, 1);
				main.insert(m, pBegin, p);
				updateIndexes(pendIndexes, *pIndex, elemSize, index);
			}
			jNum--;
		}
		startLevel++;
	}
}
