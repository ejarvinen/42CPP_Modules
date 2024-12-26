/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergeVec.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:57:50 by emansoor          #+#    #+#             */
/*   Updated: 2024/12/26 19:38:35 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../PmergeMe.hpp"

void	PmergeMe::arrangePairs(int elem1, int elem2, int N)
{
	std::vector<int>	temp;
	int					index = 0;
	int					i = elem1 + 1;

	while (i <= elem2)
	{
		temp.push_back(_sortedVec[i]);
		i++;
	}
	i = 0;
	while (i < N / 2)
	{
		_sortedVec[elem2 - i] = _sortedVec[elem1 - i];
		i++;
	}
	i--;
	while (i >= 0)
	{
		_sortedVec[elem1 - i] = temp[index];
		index++;
		i--;
	}
}

void	PmergeMe::sortElements(int pairs, int level, double N)
{
	int		elem1;
	int		elem2;
	int		pair = 1;
	int		temp;

	elem2 = N - 1;
	elem1 = 0;
	if (level != 1)
		elem1 = N - 1 - std::floor(N / 2);
	while (pair <= pairs)
	{
		if (_sortedVec.at(elem1) > _sortedVec.at(elem2))
		{
			if (level == 1)
			{
				temp = _sortedVec.at(elem1);
				_sortedVec[elem1] = _sortedVec[elem2];
				_sortedVec[elem2] = temp;
			}
			else
			{
				arrangePairs(elem1, elem2, N);
			}
		}
		elem2 = elem2 + N;
		elem1 = elem2 - N / 2;
		pair++;
	}
}

void	PmergeMe::mergeVec(int level, int pairs)
{
	double	N = pow(2, level);
	
	sortElements(pairs, level, N);
	if (pairs / 2 >= 1)
	{
		mergeVec(++level, pairs / 2);
		if (pairs > 2)
		{
			insertVec(level, pairs);
			level--;
		}
	}
	if (level == 1 && !std::is_sorted(_sortedVec.begin(), _sortedVec.end()))
	{
		insertSingles(_size);
	}
	level--;
}
