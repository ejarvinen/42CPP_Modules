/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vetorImplementation.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:57:50 by emansoor          #+#    #+#             */
/*   Updated: 2024/12/15 16:27:41 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	PmergeMe::sortVec(int level)
{
	std::vector<int>::iterator	current;
	std::vector<int>::iterator	prev;
	std::vector<int>::iterator	end;
	double N = 2 ^ level;

	prev = _sortedVec.begin();
	current = prev++;
	end = _sortedVec.end();

	while (current != end)
	{
		if (*prev > *current)
		{
			std::iter_swap(prev, current);
		}
		current = current + std::floor(N / 2);
		prev = current - 1;
	}

}
