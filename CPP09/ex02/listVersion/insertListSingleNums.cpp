/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertListSingleNums.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:20:47 by emansoor          #+#    #+#             */
/*   Updated: 2025/01/10 10:55:59 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../PmergeMe.hpp"

int	PmergeMe::insertNum(std::list<int> &main, std::list<int> &pend,
std::list<int> &pendIndexes, int pendIndex)
{
	int	index = 0;
	std::list<int>::iterator m = main.begin();
	std::list<int>::iterator p = pend.begin();
	std::list<int>::iterator pIndex = pendIndexes.begin();

	std::advance(pIndex, pendIndex);
	std::advance(p, pendIndex);
	while (index <= *pIndex && (std::size_t)index < main.size())
	{
		if (*m > *p)
		{
			main.insert(m, *p);
			updateIndexes(pendIndexes, *pIndex, 1, index);
			return (-1);
		}
		std::advance(m, 1);
		index++;
	}
	return (index);
}

void	PmergeMe::jstahlInsertSingles(std::list<int> &main, std::list<int> &pend,
std::list<int> &pendIndexes)
{
	double	jNum;
	double	prevjNum;
	int		startIndex = 3;
	int		pendIndex;
	int		index;
	int		maxIndex = getjNumIndex(pend.size());
	
	std::list<int>::iterator m;
	std::list<int>::iterator p;
	std::list<int>::iterator pIndex;

	while (startIndex <= maxIndex)
	{
		jNum = _jNums.at(startIndex);
		prevjNum = _jNums.at(startIndex - 1);
		if ((jNum - 2) > pend.size() - 1)
		{
			jNum = pend.size() + 1;
		}
		while (jNum > prevjNum)
		{
			pendIndex = jNum - 2;
			m = main.begin();
			p = pend.begin();
			pIndex = pendIndexes.begin();
			std::advance(pIndex, pendIndex);
			index = insertNum(main, pend, pendIndexes, pendIndex);
			if (index > 0)
			{
				std::advance(m, *pIndex);
				std::advance(p, pendIndex);
				if (m == main.end() || *m < *p)
					main.push_back(*p);
				else
					main.insert(m, *p);
				updateIndexes(pendIndexes, *pIndex, 1, index);
			}
			jNum--;
		}
		startIndex++;
	}
}

void	PmergeMe::insertSingleElems(int nums)
{
	std::list<int>	pend;
	std::list<int>	main;
	std::list<int>	pendIndexes;
	int				num = 0;
	int				indexAdjust = 0;

	std::list<int>::iterator elem = _sortedList.begin();

	while (num < 2)
	{
		main.push_back(*elem);
		std::advance(elem, 1);
		num++;
	}
	while (num < nums && elem != _sortedList.end())
	{
		if (num % 2 == 0)
		{
			pendIndexes.push_back(num - indexAdjust);
			pend.push_back(*elem);
			indexAdjust++;
		}
		else
			main.push_back(*elem);
		std::advance(elem, 1);
		num++;
	}
	if (pendIndexes.size() > 1)
		jstahlInsertSingles(main, pend, pendIndexes);
	else if (!pend.empty())
		binaryInsert(main, *(pend.begin()), *(pendIndexes.begin()));
	saveMain(main);
}
