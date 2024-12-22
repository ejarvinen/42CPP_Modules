/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertVecSingleNums.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:20:47 by emansoor          #+#    #+#             */
/*   Updated: 2024/12/22 17:26:31 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	PmergeMe::jacobstahlInsertSingles(std::vector<int> &main, std::vector<int> &pend, std::vector<int> &pendIndexes)
{
	double	jNum;
	double	prevjNum;
	int		startIndex = 3;
	int		elem;
	int		index;
	int		round = 0;
	int		maxIndex = getjNumIndex(pend.size());

	std::vector<int>::iterator m;
	std::vector<int>::iterator p = pend.begin();

	while (startIndex + round <= maxIndex)
	{
		jNum = _jNums.at(startIndex + round);
		prevjNum = _jNums.at(startIndex + round - 1);
		if (round == 0)
			std::advance(p, 1);
		else if (jNum - 2 >= pend.size() - 1)
		{
			p = pend.end();
			std::advance(p, -1);
			jNum = pend.size() + 1;
		}
		else
			std::advance(p, jNum - 2);
		while (jNum > prevjNum)
		{
			elem = 0;
			index = pendIndexes.at(jNum - 2);
			if ((std::size_t)index > main.size() - 1)
				index = main.size() - 1;
			m = main.begin();
			while (elem < index)
			{
				if (*m > *p)
				{
					main.insert(m, *p);
					updateJIndexes(pendIndexes, index, 1);
					index = -1;
				}
				std::advance(m, 1);
				elem++;
			}
			if (index > 0)
			{
				std::advance(m, 1);
				main.insert(m, *p);
				updateJIndexes(pendIndexes, index, 1);
			}
			if (p != pend.begin())
				std::advance(p, -1);
			jNum--;
		}
		round++;
	}
}

void	PmergeMe::insertSingles(int nums)
{
	std::vector<int>	pend;
	std::vector<int>	main;
	std::vector<int>	pendIndexes;
	int					num = 1;

	while (num <= nums)
	{
		if (num != 1 && num % 2 != 0)
		{
			pendIndexes.push_back(num - 1);
			pend.push_back(_sortedVec.at(num - 1));
		}
		else
		{
			main.push_back(_sortedVec.at(num - 1));
		}
		num++;
	}
	jacobstahlInsertSingles(main, pend, pendIndexes);
	saveMain(main);
}

/* std::cout << "main: ";
	std::vector<int>::iterator end = main.end();
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
	std::cout << std::endl; */