/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertVecSingleNums.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:20:47 by emansoor          #+#    #+#             */
/*   Updated: 2024/12/27 15:16:01 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../PmergeMe.hpp"

int	PmergeMe::insertNum(std::vector<int> &main, std::vector<int> &pend,
std::vector<int> &pendIndexes, int pendIndex)
{
	int	index = 0;
	std::vector<int>::iterator m = main.begin();

	while (index <= pendIndexes.at(pendIndex) && (std::size_t)index < main.size())
	{
		if (main.at(index) > pend.at(pendIndex))
		{
			if (index != 0)
			{
				std::advance(m, index);
			}
			main.insert(m, pend.at(pendIndex));
			updateIndexes(pendIndexes, pendIndexes.at(pendIndex), 1, index);
			return (-1);
		}
		index++;
	}
	return (index);
}

void	PmergeMe::jacobstahlInsertSingles(std::vector<int> &main, std::vector<int> &pend,
std::vector<int> &pendIndexes)
{
	double	jNum;
	double	prevjNum;
	int		startIndex = 3;
	int		pendIndex;
	int		index;
	int		maxIndex = getjNumIndex(pend.size());
	
	std::vector<int>::iterator m;

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
			index = insertNum(main, pend, pendIndexes, pendIndex);
			if (index > 0)
			{
				std::advance(m, pendIndexes.at(pendIndex));
				if (m == main.end())
					main.push_back(pend.at(pendIndex));
				else
					main.insert(m, pend.at(pendIndex));
				updateIndexes(pendIndexes, pendIndexes.at(pendIndex), 1, index);
			}
			jNum--;
		}
		startIndex++;
	}
}

void	PmergeMe::addPend(std::vector<int> &main, int pend, int pendIndex)
{
	int	index = 0;
	std::vector<int>::iterator m = main.begin();

	while (index < pendIndex && (std::size_t)index < main.size())
	{
		if (main.at(index) > pend)
		{
			if (index != 0)
				std::advance(m, index);
			main.insert(m, pend);
			index = -2;
			break ;
		}
		index++;
	}
	if (index > 0)
	{
		std::advance(m, pendIndex);
		main.insert(m, pend);
	}
}

void	PmergeMe::insertSingles(int nums)
{
	std::vector<int>	pend;
	std::vector<int>	main;
	std::vector<int>	pendIndexes;
	int					num = 0;
	int					indexAdjust = 0;

	while (num < 2)
	{
		main.push_back(_sortedVec.at(num));
		num++;
	}
	while (num < nums)
	{
		if (num % 2 == 0)
		{
			pendIndexes.push_back(num - indexAdjust);
			pend.push_back(_sortedVec.at(num));
			indexAdjust++;
		}
		else
			main.push_back(_sortedVec.at(num));
		num++;
	}
	if (pendIndexes.size() > 1)
		jacobstahlInsertSingles(main, pend, pendIndexes);
	else if (!pend.empty())
		addPend(main, pend.at(0), pendIndexes.at(0));
	saveMain(main);
}
