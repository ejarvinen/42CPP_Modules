/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertVec.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:45:29 by emansoor          #+#    #+#             */
/*   Updated: 2024/12/18 18:06:49 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	PmergeMe::clearPend(std::vector<int> &main, std::vector<int> &pend, std::vector<int> &pendIndexes, double N)
{
	int	pendElem;
	int	elem;
	int	index;
	int	i;

	if (pendIndexes.size() > 2)
	{
		// jacobstahl;
		return ;
	}
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
			std::advance(m, N / 2 - 1);
			if (*m > *p)
			{
				std::advance(m, (-1) * (N / 2 - 1));
				std::advance(p, (-1) * (N / 2 - 1));
				main.insert(m, p, p + (N / 2 - 1)); // is this safe
				index = -1;
			}
			elem++;
			pendElem = pendElem * elem;
		}
		if (index > 0)
		{
			std::advance(p, (-1) * (N / 2 - 1));
			main.insert(m, p, p + (N / 2 - 1)); // is this safe
		}
		std::advance(it, 1);
	}
}

void	PmergeMe::insertVec(int level, int pairs)
{
	std::vector<int>	pend;
	std::vector<int>	main;
	std::vector<int>	pendIndexes;
	std::vector<int>	oddb;
	int					pair = 1;
	int					i;
	int					elem;
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
			elem = (pair - 1) * N / 2;
			pendIndexes.push_back(elem);
			i = 0;
			while (i < N / 2)
			{
				pend.push_back(_sortedVec[elem + i]);
				i++;
			}
		}
		else
		{
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
		pair++;
	}
	if (odd)
	{
		elem = pairs * (N / 2);
		i = 0;
		while (i < N / 2)
		{
			oddb.push_back(_sortedVec[elem + i]);
			i++;
		}
	}
	
	clearPend(main, pend, pendIndexes, N);
	// insert odd element

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