/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jacobstahlInsert.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:03:27 by emansoor          #+#    #+#             */
/*   Updated: 2024/12/22 17:27:18 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

double PmergeMe::jacobstahl(double n)
{
    if (n == 0)
        return (0);
    if (n == 1)
        return (1);
    return (jacobstahl(n - 1) + 2 * jacobstahl(n - 2));
}

void	PmergeMe::initJacobstahl(void)
{
	int		index = 0;
	double	jNum = 0;

	jNum = jacobstahl(index);
	while (jNum <= (double)_size)
	{
		_jNums.push_back(jNum);
		index++;
		jNum = jacobstahl(index);
	}
	_jNums.push_back(jNum);
}

int	PmergeMe::getjNumIndex(double pendSize)
{
	int	index = 0;
	std::deque<double>::iterator it = _jNums.begin();
	std::deque<double>::iterator end = _jNums.end();

	while (it != end && *it <= pendSize)
	{
		index++;
		std::advance(it, 1);
	}
	return (index);
}

void	PmergeMe::updateJIndexes(std::vector<int> &pendIndexes, int index, double increment)
{
	std::vector<int>::iterator it = pendIndexes.begin();
	std::vector<int>::iterator end = pendIndexes.end();

	while (it != end && *it != index)
	{
		*it = (double)*it + increment;
		std::advance(it, 1);
	}
}

void	PmergeMe::jacobstahlInsert(std::vector<int> &main, std::vector<int> &pend, std::vector<int> &pendIndexes, double N)
{
	double	jNum;
	double	prevjNum;
	int		startIndex = 3;
	int		pendElem;
	int		index;
	int		round = 0;
	int		maxIndex = getjNumIndex(pend.size() / (N / 2));

	std::vector<int>::iterator m;
	std::vector<int>::iterator p = pend.begin();

	while (startIndex + round <= maxIndex)
	{
		jNum = _jNums.at(startIndex + round);
		prevjNum = _jNums.at(startIndex + round - 1);
		if (round == 0)
			std::advance(p, (N / 2 - 1) * jNum);
		else if ((N / 2 - 1) * jNum + (jNum - prevjNum) > pend.size())
		{
			p = pend.end();
			std::advance(p, -1);
			jNum = pend.size() / (N / 2) + 1; // use jNum = maxIndex?
		}
		else
			std::advance(p, (N / 2 - 1) * jNum + (jNum - prevjNum));
		while (jNum > prevjNum)
		{
			pendElem = N / 2 - 1;
			index = pendIndexes.at(jNum - 2);
			m = main.begin();
			std::advance(m, (N / 2 - 1));
			while (pendElem < index)
			{
				if (*m > *p)
				{
					std::advance(m, (-1) * (N / 2 - 1));
					std::advance(p, (-1) * (N / 2 - 1));
					main.insert(m, p, p + (N / 2)); // is this safe
					updateJIndexes(pendIndexes, index, N / 2);
					index = -1;
				}
				pendElem = pendElem + (N / 2);
				std::advance(m, N / 2);
			}
			if (index > 0)
			{
				std::advance(m, -1);
				std::advance(p, (-1) * (N / 2 - 1));
				main.insert(m, p, p + (N / 2)); // is this safe
				updateJIndexes(pendIndexes, index, N / 2);
			}
			if (p != pend.begin())
				std::advance(p, -1);
			jNum--;
		}
		//p = pend.begin();
		round++;
	}
}

/* std::cout << "Jacobstahl numbers:" << std::endl;
	std::deque<double>::iterator it = _jNums.begin();
	std::deque<double>::iterator end = _jNums.end();
	while (it != end)
	{
		std::cout << *it << std::endl;
		std::advance(it, 1);
	} */