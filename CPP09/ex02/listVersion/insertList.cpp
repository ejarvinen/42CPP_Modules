/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertList.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:45:29 by emansoor          #+#    #+#             */
/*   Updated: 2025/01/08 15:25:40 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../PmergeMe.hpp"

void	PmergeMe::saveMain(std::list<int> &main)
{
	std::list<int>::iterator m = main.begin();
	std::list<int>::iterator end = main.end();
	std::list<int>::iterator l = _sortedList.begin();

	while (m != end)
	{
		*l = *m;
		std::advance(m, 1);
		std::advance(l, 1);
	}
}

void	PmergeMe::updateIndexes(std::list<int> &pendIndexes, int pendIndex,
double increment, int mainIndex)
{
	std::list<int>::iterator it = pendIndexes.begin();
	std::list<int>::iterator end = pendIndexes.end();

	if (mainIndex < pendIndex)
	{
		while (it != end && *it != pendIndex)
		{
			*it = (double)*it + increment;
			std::advance(it, 1);
		}
	}
	else
	{
		while (it != end && *it != pendIndex)
			std::advance(it, 1);
	}
	if (it == end)
		return ;
	std::advance(it, 1);
	while (it != end)
	{
		*it = (double)*it + increment;
		std::advance(it, 1);
	}
}

void	PmergeMe::initPendIndexes(std::list<int> &pendIndexes, double N, int pair)
{
	int	index;
	std::list<int>::iterator elem = pendIndexes.begin();
	
	if (pair / 2 == 1)
		index = pair * (N / 2);
	else
	{
		if (pair / 2 != 2)
			std::advance(elem, (pair / 2) - 2);
		index = *elem + N / 2;
	}
	pendIndexes.push_back(index);
}

void	PmergeMe::initElem(std::list<int> &main, double N, int pair)
{
	int	i = 0;
	std::list<int>::iterator elem = _sortedList.begin();

	std::advance(elem, pair * (N / 2));
	while (i < N / 2)
	{
		main.push_back(*elem);
		std::advance(elem, 1);
		i++;
	}
}

void	PmergeMe::splitElems(std::list<int> &main, std::list<int> &pend,
std::list<int> &pendIndexes, int pairs, double N)
{
	int	pair = 0;

	while (pair < 2)
	{
		initElem(main, N, pair);
		pair++;
	}
	while (pair < pairs)
	{
		if (pair % 2 == 0)
		{
			initPendIndexes(pendIndexes, N, pair);
			initElem(pend, N, pair);
		}
		else
		{
			initElem(main, N, pair);
		}
		pair++;
	}
}

void	PmergeMe::insertList(int level, int pairs)
{
	std::list<int>	pend;
	std::list<int>	main;
	std::list<int>	pendIndexes;
	std::list<int>	odd;
	bool			oddElement = false;
	double			N = pow(2, level);
	
	if (pairs % 2 != 0)
	{
		oddElement = true;
		pairs--;
	}
	splitElems(main, pend, pendIndexes, pairs, N);
	if (oddElement)
		initElem(odd, N, pairs);
	if (pendIndexes.size() > 1)
		jstahlInsert(main, pend, pendIndexes, N);
	else if (!pend.empty())
		binaryInsertElems(main, pend, *(pendIndexes.begin()));
	if (oddElement)
		binaryInsertElems(main, odd, main.size() - 1);
	saveMain(main);
}
