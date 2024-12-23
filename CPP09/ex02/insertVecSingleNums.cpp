/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertVecSingleNums.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:20:47 by emansoor          #+#    #+#             */
/*   Updated: 2024/12/23 16:19:38 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	PmergeMe::jacobstahlInsertSingles(std::vector<int> &main, std::vector<int> &pend, std::vector<int> &pendIndexes)
{
	double	jNum;
	double	prevjNum;
	int		startIndex = 3;
	int		pendIndex;
	int		index;
	int		maxIndex = getjNumIndex(pend.size());

	std::vector<int>::iterator m;
	std::vector<int>::iterator p = pend.begin();

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
			pendIndex = jNum - 2; // index for pend elements
			m = main.begin();
			p = pend.begin();
			index = 0;
			while (index < pendIndexes.at(pendIndex) && (std::size_t)index < main.size() && index != -1)
			{
				if (main.at(index) > pend.at(pendIndex))
				{
					if (index != 0)
					{
						std::advance(m, index);
					}
					std::advance(p, pendIndex); // do these need to be protected?
					main.insert(m, *p);
					updateJIndexes(pendIndexes, pendIndex, 1);
					index = -2;
				}
				index++;
			}
			if (index > 0)
			{
				std::advance(m, pendIndexes.at(pendIndex)); // does this need to be protected
				main.insert(m, *p);
			}
			jNum--;
		}
		startIndex++;
	}
}

void	PmergeMe::insertSingles(int nums)
{
	std::vector<int>	pend;
	std::vector<int>	main;
	std::vector<int>	pendIndexes;
	int					num = 0;

	while (num < 2)
	{
		main.push_back(_sortedVec.at(num));
		num++;
	}
	while (num < nums)
	{
		if (num % 2 == 0)
		{
			pendIndexes.push_back(num);
			pend.push_back(_sortedVec.at(num));
		}
		else
		{
			main.push_back(_sortedVec.at(num));
		}
		num++;
	}
	if (pendIndexes.size() > 1)
		jacobstahlInsertSingles(main, pend, pendIndexes);
	else
		insertPend(main, pend, pendIndexes.at(0));
	_sortedVec.assign(main.begin(), main.end());
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