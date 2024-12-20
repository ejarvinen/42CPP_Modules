/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertVec.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:45:29 by emansoor          #+#    #+#             */
/*   Updated: 2024/12/20 19:57:00 by emansoor         ###   ########.fr       */
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
		std::advance(v, 1);
		std::advance(m, 1);
	}
}

void	PmergeMe::insertOdd(std::vector<int> &main, std::vector<int> &oddb, double N)
{
	std::vector<int>::iterator m = main.begin();
	std::vector<int>::iterator o = oddb.end();
	int	pairs = main.size() / (N / 2);
	int	comparisons = 0;
	
	std::advance(o, -1);
	while (comparisons < pairs)
	{
		if (comparisons == 0)
			std::advance(m, (N / 2 - 1));
		else
			std::advance(m, N / 2);
		if (*m > *o)
		{
			std::advance(m, (-1) * (N / 2 - 1));
			std::advance(o, (-1) * (N / 2 - 1));
			main.insert(m, o, o + (N / 2)); // is this safe
			return ;
		}
		comparisons++;
	}
}

void	PmergeMe::updateIndexes(std::vector<int> &pendIndexes, int index, double increment)
{
	std::vector<int>::iterator it = pendIndexes.begin();
	std::vector<int>::iterator end = pendIndexes.end();

	while (*it != index)
		std::advance(it, 1);
	if (it == end)
		return ;
	std::advance(it, 1);
	while (it != end)
	{
		*it = (double)*it + increment;
		std::advance(it, 1);
	}
}

void	PmergeMe::clearPend(std::vector<int> &main, std::vector<int> &pend, std::vector<int> &pendIndexes, double N)
{
	int	pendElem;
	int	elem;
	int	index;

	std::vector<int>::iterator it = pendIndexes.begin();
	std::vector<int>::iterator end = pendIndexes.end();
	std::vector<int>::iterator m = main.begin();
	std::vector<int>::iterator p = pend.begin();
	pendElem = N / 2 - 1;
	while (it != end)
	{
		index = *it;
		elem = 1;
		std::advance(p, pendElem);
		while (pendElem < index)
		{
			if (elem == 1)
				std::advance(m, (N / 2 - 1));
			else
				std::advance(m, N / 2);
			if (*m > *p)
			{
				std::advance(m, (-1) * (N / 2 - 1));
				std::advance(p, (-1) * (N / 2 - 1));
				main.insert(m, p, p + (N / 2)); // is this safe
				updateIndexes(pendIndexes, index, N / 2);
				index = -1;
			}
			elem++;
			pendElem = pendElem * elem;
		}
		if (index > 0)
		{
			std::advance(m, 1);
			std::advance(p, (-1) * (N / 2 - 1));
			main.insert(m, p, p + (N / 2)); // is this safe
			updateIndexes(pendIndexes, index, N / 2);
		}
		std::advance(it, 1);
	}
}

void	PmergeMe::fillPend(std::vector<int> &pend, std::vector<int> &pendIndexes, double N, int pair)
{
	int	elem;
	int	i;

	elem = (pair - 1) * N / 2;
	pendIndexes.push_back(elem);
	i = 0;
	while (i < N / 2)
	{
		pend.push_back(_sortedVec[elem + i]);
		i++;
	}
}

void	PmergeMe::fillMain(std::vector<int>	&main, double N, int pair)
{
	int	elem;
	int	i;

	if (pair == 1)
	{
		i = 0;
		while (i < N)
		{
			main.push_back(_sortedVec[i]);
			i++;
		}
	}
	else if (pair > 2)
	{
		elem = (pair - 1) * (N / 2);
		i = 0;
		while (i < N / 2)
		{
			main.push_back(_sortedVec[elem + i]);
			i++;
		}
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
	int					pair = 1;
	bool				odd = false;
	double				N = pow(2, level);

	if (pairs % 2 != 0)
	{
		odd = true;
		pairs--;
	}
	while (pair <= pairs)
	{
		if (pair != 1 && pair % 2 != 0)
		{
			fillPend(pend, pendIndexes, N, pair);
		}
		else
		{
			fillMain(main, N, pair);
		}
		pair++;
	}
	if (odd)
	{
		saveOdd(oddb, pairs, N);
	}
	if (pendIndexes.size() > 2)
	{
		// jacobstahl;
	}
	else
		clearPend(main, pend, pendIndexes, N);
	if (odd)
		insertOdd(main, oddb, N);
	saveMain(main);
	std::cout << "og: ";
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
	}
}