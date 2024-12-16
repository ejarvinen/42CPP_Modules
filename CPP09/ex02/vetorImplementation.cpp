/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vetorImplementation.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:57:50 by emansoor          #+#    #+#             */
/*   Updated: 2024/12/16 15:03:02 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	PmergeMe::sortVec(int level, int pairs)
{
	std::vector<int>::iterator	elem1;
	std::vector<int>::iterator	elem2;
	int							pair = 1;
	double						N = 2 ^ level;

	elem1 = _sortedVec.begin();
	elem2 = elem1;
	std::advance(elem2, N - 1);
	std::advance(elem1, std::floor(N / 2));
	while (pair <= pairs)
	{
		if (*elem1 > *elem2)
		{
			std::swap(elem1, elem2); // figure out how to do this with pairs of pairs....
		}
		std::advance(elem2, N);
		elem1 = elem2;
		std::advance(elem1, (-1) * std::floor(N / 2));
		pair++;
	}
	if (pairs / 2 > 1)
	{
		sortVec(level++, std::floor(pairs / 2));
	}
	// do the insert sort with jacobstahl numbers
}
