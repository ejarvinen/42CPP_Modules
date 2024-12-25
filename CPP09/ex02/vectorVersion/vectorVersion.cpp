/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorVersion.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 17:44:13 by emansoor          #+#    #+#             */
/*   Updated: 2024/12/25 18:23:59 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../PmergeMe.hpp"

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

void	PmergeMe::runVectorVersion(void)
{
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
}
