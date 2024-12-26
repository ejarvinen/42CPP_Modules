/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergeList.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:57:50 by emansoor          #+#    #+#             */
/*   Updated: 2024/12/26 19:34:17 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../PmergeMe.hpp"

void	PmergeMe::swapPairs(std::list<int>::iterator elem, std::list<int>::iterator prev, int N)
{
	std::list<int>	temp;
	std::list<int>::iterator	it;
	int	index = 0;

	while (index < N / 2)
	{
		temp.push_back(*elem);
		std::advance(elem, -1);
		std::advance(prev, -1);
		index++;
	}
	std::advance(elem, 1);
	std::advance(prev, 1);
	while (index > 0)
	{
		*elem = *prev;
		std::advance(elem, 1);
		std::advance(prev, 1);
		index--;
	}
	std::advance(prev, -1);
	it = temp.begin();
	while (it != temp.end())
	{
		*prev = *it;
		std::advance(prev, -1);
		std::advance(it, 1);
	}
	
}

void	PmergeMe::sortElems(int pairs, int level, double N)
{
	int		elem1;
	int		elem2;
	int		pair = 1;
	int		temp;

	std::list<int>::iterator elem = _sortedList.begin();
	std::list<int>::iterator prev = _sortedList.begin();

	elem2 = N - 1;
	elem1 = 0;
	if (level != 1)
		elem1 = N - 1 - std::floor(N / 2);
	std::advance(elem, elem2);
	std::advance(prev, elem1);
	while (pair <= pairs && elem != _sortedList.end())
	{
		if (*prev > *elem)
		{
			if (level == 1)
			{
				temp = *prev;
				*prev = *elem;
				*elem = temp;
			}
			else
			{
				swapPairs(elem, prev, N);
			}
		}
		std::advance(elem, N);
		std::advance(prev, N);
		pair++;
	}
}

void	PmergeMe::mergeList(int level, int pairs)
{
	double	N = pow(2, level);
	
	sortElems(pairs, level, N);
	if (pairs / 2 >= 1)
	{
		mergeList(++level, pairs / 2);
		if (pairs > 2)
		{
			insertList(level, pairs);
			level--;
		}
	}
	if (level == 1 && !std::is_sorted(_sortedList.begin(), _sortedList.end()))
	{
		insertSingleElems(_size);
	}
	level--;
}
