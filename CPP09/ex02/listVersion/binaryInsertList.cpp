/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binaryInsertList.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:21:06 by emansoor          #+#    #+#             */
/*   Updated: 2025/01/10 10:56:16 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../PmergeMe.hpp"

void	PmergeMe::binaryInsertElems(std::list<int> &main, std::list<int> &pend, int pendIndex)
{
	std::size_t	elemSize = pend.size();
	int	low = (elemSize - 1);
	int	high = pendIndex;
	int mid;
	std::list<int>::iterator p = pend.begin();
	std::list<int>::iterator m = main.begin();
	std::list<int>::iterator mLast = main.end();
	std::list<int>::iterator pStart = pend.begin();

	std::advance(p, elemSize - 1);
	std::advance(mLast, -1);
	while (low < high)
	{
		if (main.size() / elemSize == 2)
			mid = low;
		else
			mid = ((high - low) / (elemSize)) + low;

		std::advance(m, mid);
		if (*m < *p)
			low = mid + elemSize;
		else
			high = mid - elemSize;
		m = main.begin();
	}
	if (high > 0)
	{
		std::advance(m, high);
		if (*m > *p)
			std::advance(m, -elemSize);
	}
	if (*m < *p && m != main.end() && *m == *mLast && high > 0)
	{
		std::advance(p, 1);
		while (pStart != p)
		{
			main.push_back(*pStart);
			std::advance(pStart, 1);
		}
	}
	else
	{
		if (*m < *p && m != main.begin())
			std::advance(m, 1);
		std::advance(p, 1);
		main.insert(m, pStart, p);
	}
}


void	PmergeMe::binaryInsert(std::list<int> &main, int pend, int pendIndex)
{
	std::list<int>::iterator m = main.begin();
	int	low = 0;
	int	high = pendIndex;

	while (low < high)
	{
		int mid = ((high - low) / 2) + low;
		
		std::advance(m, mid);
		if (*m < pend)
			low = mid + 1;
		else
			high = mid - 1;
		m = main.begin();
	}
	if (high > 0)
		std::advance(m, high);
	if (*m < pend && m != main.end())
		std::advance(m, 1);
	main.insert(m, pend);
}
