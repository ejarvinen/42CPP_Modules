/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:10:26 by emansoor          #+#    #+#             */
/*   Updated: 2024/12/25 15:43:36 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _unsorted(NULL), _size(0), _even(true), _straggler(-1) {}

PmergeMe::PmergeMe(PmergeMe const &copy) : _sortedVec(copy._sortedVec), _sortedList(copy._sortedList), _jNums(copy._jNums)
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
		_jNums = other._jNums;
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
	_size = index - 1;
	return (0);
}

void	PmergeMe::addOdd(void)
{
	std::vector<int>::iterator begin = _sortedVec.begin();
	std::vector<int>::iterator end = _sortedVec.end();

	while (begin != end)
	{
		if (*begin > _straggler)
		{
			_sortedVec.insert(begin, _straggler);
			return ;
		}
		std::advance(begin, 1);
	}
	_sortedVec.push_back(_straggler);
}

void	PmergeMe::sortNums(char **argv)
{
	if (checkArgs(argv))
	{
		std::cout << "Error: invalid arguments" << std::endl;
		return ;
	}
	_unsorted = argv;
	std::vector<int>::iterator last = _sortedVec.end();
	if (!std::is_sorted(_sortedVec.begin(), last))
	{
		if (_size % 2 != 0)
		{
			_even = false;
			std::advance(last, -1);
			_straggler = *last;
			_sortedVec.pop_back();
			_size--;
		}
		initJacobstahl();
		mergeVec(1, _size / 2);
		if (!std::is_sorted(_sortedVec.begin(), _sortedVec.end()))
			insertSingles(_size);
		if (!_even)
			addOdd();
	}
	std::cout << "og: ";
	std::vector<int>::iterator end = _sortedVec.end();
	for (std::vector<int>::iterator it = _sortedVec.begin(); it != end; std::advance(it, 1))
		std::cout << *it << " ";
	std::cout << std::endl;
	//sortList();
	//printStats();
}
