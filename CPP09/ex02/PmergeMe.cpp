/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:10:26 by emansoor          #+#    #+#             */
/*   Updated: 2024/12/25 17:50:07 by emansoor         ###   ########.fr       */
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

void	PmergeMe::sortNums(char **argv)
{
	if (checkArgs(argv))
	{
		std::cout << "Error: invalid arguments" << std::endl;
		return ;
	}
	runVectorVersion();
	std::cout << "og: ";
	std::vector<int>::iterator end = _sortedVec.end();
	for (std::vector<int>::iterator it = _sortedVec.begin(); it != end; std::advance(it, 1))
		std::cout << *it << " ";
	std::cout << std::endl;
	//sortList();
	//printStats();
}
