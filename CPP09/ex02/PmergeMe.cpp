/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:10:26 by emansoor          #+#    #+#             */
/*   Updated: 2024/12/27 15:15:48 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _unsorted(NULL), _vecTime(0), _listTime(0), _size(0), _even(true), _straggler(-1) {}

PmergeMe::PmergeMe(PmergeMe const &copy) : _sortedVec(copy._sortedVec), _sortedList(copy._sortedList), _jNums(copy._jNums)
{
	_unsorted = copy._unsorted;
	_size = copy._size;
	_even = copy._even;
	_straggler = copy._straggler;
	_vecTime = copy._vecTime;
	_listTime = copy._listTime;
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
		_vecTime = other._vecTime;
		_listTime = other._listTime;
	}
	return (*this);
}

void	PmergeMe::printStats(void)
{
	int	index;

	std::cout << "Before:   ";
	for (index = 1; index < _size; index++)
	{
		if (index == 5 && _size > 5)
		{
			std::cout << "[...]";
			break ;
		}
		std::cout << _unsorted[index] << " ";
	}
	std::cout << std::endl;
	std::cout << "After:    ";
	index = 0;
	for (std::vector<int>::iterator begin = _sortedVec.begin(); begin != _sortedVec.end(); std::advance(begin, 1))
	{
		if (index == 4 && _size > 5)
		{
			std::cout << "[...]";
			break ;
		}
		std::cout << *begin << " ";
		index++;
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of " << _size << " elements with std::vector : " << _vecTime << " us" << std::endl;
	std::cout << "Time to process a range of " << _size << " elements with std::list : " << _listTime << " us" << std::endl;
}

void	PmergeMe::sortNums(char **argv)
{
	if (checkArgs(argv))
	{
		std::cerr << "Error: invalid arguments" << std::endl;
		return ;
	}
	runVectorVersion();
	runListVersion();
	printStats();
}
