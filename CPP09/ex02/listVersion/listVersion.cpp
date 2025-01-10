/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listVersion.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 17:44:13 by emansoor          #+#    #+#             */
/*   Updated: 2025/01/10 09:30:42 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../PmergeMe.hpp"

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
		while (!std::is_sorted(_sortedList.begin(), _sortedList.end()))
			insertSingleElems(_size);
		if (!_even)
		{
			binaryInsert(_sortedList, _straggler, _size);
			_size++;
		}
	}
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	_listTime = std::chrono::duration<double>(end - begin).count();
}
