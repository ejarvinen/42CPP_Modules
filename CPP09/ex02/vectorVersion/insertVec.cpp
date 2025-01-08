/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertVec.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:45:29 by emansoor          #+#    #+#             */
/*   Updated: 2025/01/08 12:16:58 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../PmergeMe.hpp"

void	PmergeMe::saveMain(std::vector<int> &main)
{
	std::vector<int>::iterator m = main.begin();
	std::vector<int>::iterator end = main.end();
	std::vector<int>::iterator v = _sortedVec.begin();

	while (m != end)
	{
		*v = *m;
		std::advance(m, 1);
		std::advance(v, 1);
	}
}

void	PmergeMe::updateIndexes(std::vector<int> &pendIndexes, int pendIndex,
double increment, int mainIndex)
{
	std::vector<int>::iterator it = pendIndexes.begin();
	std::vector<int>::iterator end = pendIndexes.end();

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

void	PmergeMe::initPendIndexes(std::vector<int> &pendIndexes, double N, int pair)
{
	int	index;

	if (pair / 2 == 1)
		index = pair * (N / 2);
	else
		index = pendIndexes.at((pair / 2) - 2) + (N / 2);
	pendIndexes.push_back(index);
}

void	PmergeMe::initElem(std::vector<int>	&main, double N, int pair)
{
	int	elem;
	int	i;

	elem = pair * (N / 2);
	i = 0;
	while (i < N / 2)
	{
		main.push_back(_sortedVec.at(elem + i));
		i++;
	}
}

void	PmergeMe::splitElements(std::vector<int> &main, std::vector<int> &pend, std::vector<int> &pendIndexes, int pairs, double N)
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

void	PmergeMe::insertVec(int level, int pairs)
{
	std::vector<int>	pend;
	std::vector<int>	main;
	std::vector<int>	pendIndexes;
	std::vector<int>	odd;
	bool				oddElement = false;
	double				N = pow(2, level);

	if (pairs % 2 != 0)
	{
		oddElement = true;
		pairs--;
	}
	splitElements(main, pend, pendIndexes, pairs, N);
	if (oddElement)
		initElem(odd, N, pairs);
	if (pendIndexes.size() > 1)
		jacobstahlInsert(main, pend, pendIndexes, N);
	else if (!pend.empty())
		binaryInsertElems(main, pend, pendIndexes.at(0));
	if (oddElement)
		binaryInsertElems(main, odd, main.size() - 1);
	saveMain(main);
}
