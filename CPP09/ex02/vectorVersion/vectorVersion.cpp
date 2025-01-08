/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorVersion.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 17:44:13 by emansoor          #+#    #+#             */
/*   Updated: 2025/01/08 10:23:29 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../PmergeMe.hpp"

void	PmergeMe::runVectorVersion(void)
{
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

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
		while (!std::is_sorted(_sortedVec.begin(), _sortedVec.end()))
			insertSingles(_size);
		if (!_even)
		{
			binaryInsert(_sortedVec, _straggler, _size);
			_size++;
		}
	}
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	_vecTime = std::chrono::duration<double>(end - begin).count();
}
