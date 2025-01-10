/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binaryInsertVec.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:30:12 by emansoor          #+#    #+#             */
/*   Updated: 2025/01/10 09:18:06 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../PmergeMe.hpp"

void	PmergeMe::binaryInsertElems(std::vector<int> &main, std::vector<int> &pend, int pendIndex)
{
	std::size_t	elemSize = pend.size();
	int	low = (elemSize - 1);
	int	high = pendIndex;
	int mid;
	std::vector<int>::iterator p = pend.begin();
	std::vector<int>::iterator m = main.begin();

	while (low < high)
	{
		if (main.size() / elemSize == 2)
			mid = low;
		else
			mid = ((high - low) / (elemSize)) + low;
			
		if (main.at(mid) < pend.at(elemSize - 1))
			low = mid + elemSize;
		else
			high = mid - elemSize;
	}
	if (high > 0)
		std::advance(m, high - (elemSize - 1));
	main.insert(m, p, p + elemSize);
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
	if (high > 0)
		std::advance(m, high);
	if (*m < pend)
		std::advance(m, 1);
	main.insert(m, pend);
}
