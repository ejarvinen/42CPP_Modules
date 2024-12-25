/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertVec.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:45:29 by emansoor          #+#    #+#             */
/*   Updated: 2024/12/25 17:40:43 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

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

void	PmergeMe::updateIndexes(std::vector<int> &pendIndexes, int pendIndex, double increment, int mainIndex)
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

void	PmergeMe::insertPend(std::vector<int> &main, std::vector<int> &pend, int pendIndex)
{
	std::size_t	elemSize = pend.size();
	int	index = (elemSize - 1);
	std::vector<int>::iterator p = pend.begin();
	std::vector<int>::iterator m = main.begin();

	while (index > -1 && index <= pendIndex && (std::size_t)index < main.size())
	{
		if (main.at(index) > pend.at(elemSize - 1))
		{
			if (index != (int)elemSize - 1)
				std::advance(m, index - (elemSize - 1));
			main.insert(m, p, p + elemSize);
			index = -1 - (index + elemSize);
		}
		index = index + elemSize;
	}
	if (index > 0)
	{
		std::advance(m, pendIndex);
		if (*m == main.at(main.size() - 1) && *m < pend.at(elemSize - 1))
			std::advance(m, 1);
		main.insert(m, p, p + elemSize);
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

void	PmergeMe::initPend(std::vector<int> &pend, double N, int pair)
{
	int	elem;
	int	i;

	elem = pair * (N / 2);
	i = 0;
	while (i < (N / 2))
	{
		pend.push_back(_sortedVec[elem + i]);
		i++;
	}
}

void	PmergeMe::initMain(std::vector<int>	&main, double N, int pair)
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

void	PmergeMe::saveOdd(std::vector<int> &oddb, int pairs, double N)
{
	int	elem;
	int	i;

	elem = pairs * (N / 2);
	i = 0;
	while (i < N / 2)
	{
		oddb.push_back(_sortedVec[elem + i]);
		i++;
	}
}

void	PmergeMe::insertVec(int level, int pairs)
{
	std::vector<int>	pend;
	std::vector<int>	main;
	std::vector<int>	pendIndexes;
	std::vector<int>	oddb;
	int					pair = 0;
	bool				odd = false;
	double				N = pow(2, level);

	if (pairs % 2 != 0)
	{
		odd = true;
		pairs--;
	}
	while (pair < 2)
	{
		initMain(main, N, pair);
		pair++;
	}
	while (pair < pairs)
	{
		if (pair % 2 == 0)
		{
			initPendIndexes(pendIndexes, N, pair);
			initPend(pend, N, pair);
		}
		else
		{
			initMain(main, N, pair);
		}
		pair++;
	}
	if (odd)
	{
		saveOdd(oddb, pairs, N);
	}
	if (pendIndexes.size() > 1)
	{
		jacobstahlInsert(main, pend, pendIndexes, N);
	}
	else if (!pend.empty())
		insertPend(main, pend, pendIndexes.at(0));
	if (odd)
	{
		insertPend(main, oddb, main.size() - 1);
	}
	saveMain(main);
}

/* std::cout << "og: ";
	std::vector<int>::iterator end = _sortedVec.end();
	for (std::vector<int>::iterator it = _sortedVec.begin(); it != end; std::advance(it, 1))
		std::cout << *it << " ";
	std::cout << std::endl;
	
	std::cout << "main: ";
	end = main.end();
	for (std::vector<int>::iterator it = main.begin(); it != end; std::advance(it, 1))
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "pend: ";
	end = pend.end();
	for (std::vector<int>::iterator it = pend.begin(); it != end; std::advance(it, 1))
		std::cout << *it << " ";
	std::cout << std::endl;
	
	std::cout << "indexes: ";
	end = pendIndexes.end();
	for (std::vector<int>::iterator it = pendIndexes.begin(); it != end; std::advance(it, 1))
		std::cout << *it << " ";
	std::cout << std::endl;

	if (odd)
	{
		std::cout << "odd: ";
		end = oddb.end();
		for (std::vector<int>::iterator it = oddb.begin(); it != end; std::advance(it, 1))
			std::cout << *it << " ";
		std::cout << std::endl;
	} */