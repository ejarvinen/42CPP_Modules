/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:10:26 by emansoor          #+#    #+#             */
/*   Updated: 2024/12/15 16:32:51 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _unsorted(NULL), _size(0), _even(true), _straggler(-1) {}

PmergeMe::PmergeMe(PmergeMe const &copy) : _sortedVec(copy._sortedVec), _sortedList(copy._sortedList)
{
	_unsorted = copy._unsorted;
	_size = copy._size;
	_even = copy._even;
	_straggler = copy._straggler;
}

PmergeMe::~PmergeMe() {}

PmergeMe	&PmergeMe::operator=(PmergeMe const &other)
{
	if (this != &other)
	{
		_unsorted = other._unsorted;
		_sortedVec = other._sortedVec;
		_sortedList = other._sortedList;
		_even = other._even;
		_straggler = other._straggler;
		_size = other._size;
	}
	return (*this);
}

bool	PmergeMe::isAllDigits(std::string num)
{
	for (int index = 0; num[index]; index++)
	{
		if (std::isdigit(num[index]) == 0)
			return (false);
	}
	return (true);
}

int	PmergeMe::checkArgs(char **argv)
{
	int index;
	int	num;

	for (index = 1; argv[index]; index++)
	{
		if (isAllDigits(argv[index]))
		{
			try
			{
				num = std::stoi(argv[index]);
			}
			catch (const std::exception& e)
			{
				return (1);
			}
			_sortedVec.push_back(num);
			_sortedList.push_back(num);
		}
		else
			return (1);
	}
	_size = index;
	return (0);
}

void	PmergeMe::sortNums(char **argv)
{
	if (checkArgs(argv))
	{
		std::cout << "Error: invalid arguments" << std::endl;
		return ;
	}
	std::vector<int>::iterator last = _sortedVec.end();
	last--;
	if (_size % 2 != 0)
	{
		_even = false;
		_straggler = *last;
	}
	sortVec(1);
	sortList();
	printStats();
}
