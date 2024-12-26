/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listVersion.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 17:44:13 by emansoor          #+#    #+#             */
/*   Updated: 2024/12/26 19:21:58 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../PmergeMe.hpp"

void	PmergeMe::insertOdd(void)
{
	std::list<int>::iterator begin = _sortedList.begin();
	std::list<int>::iterator end = _sortedList.end();

	while (begin != end)
	{
		if (*begin > _straggler)
		{
			_sortedList.insert(begin, _straggler);
			return ;
		}
		std::advance(begin, 1);
	}
	_sortedList.push_back(_straggler);
}

void	PmergeMe::runListVersion(void)
{
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	std::list<int>::iterator last = _sortedList.end();
	if (!std::is_sorted(_sortedList.begin(), last))
	{
		if (_size % 2 != 0)
		{
			_even = false;
			std::advance(last, -1);
			_straggler = *last;
			_sortedList.pop_back();
			_size--;
		}
		initJacobstahl();
		mergeList(1, _size / 2);
		if (!std::is_sorted(_sortedList.begin(), _sortedList.end()))
			insertSingleElems(_size);
		if (!_even)
		{
			insertOdd();
			_size++;
		}
	}
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	_listTime = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
}
