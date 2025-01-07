/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binaryInsertVec.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:30:12 by emansoor          #+#    #+#             */
/*   Updated: 2025/01/07 15:45:38 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../PmergeMe.hpp"

void	PmergeMe::binaryInsert(std::vector<int> &main, std::vector<int> &pend, int pendIndex)
{
	std::size_t	elemSize = pend.size();
	int	low = (elemSize - 1);
	int	high = pendIndex;
	std::vector<int>::iterator p = pend.begin();
	std::vector<int>::iterator m = main.begin();

	while (low < high)
	{
		int mid = ((high - low) / 2) + low;

		if (main.at(mid) < pend.at(elemSize - 1))
			low = mid + elemSize;
		else
			high = mid - elemSize;
	}
	// finish inserting here
}


void	PmergeMe::binaryInsert(std::vector<int> &main, int pend, int pendIndex)
{
	std::vector<int>::iterator m = main.begin();
	int	low = 0;
	int	high = pendIndex;

	while (low < high)
	{
		int mid = ((high - low) / 2) + low;
		
		if (main.at(mid) < pend)
			low = mid + 1;
		else
			high = mid - 1;
	}
	if (high == 0)
		main.insert(m, pend);
	else
	{
		std::advance(m, high);
		main.insert(m, pend);
	}
}
