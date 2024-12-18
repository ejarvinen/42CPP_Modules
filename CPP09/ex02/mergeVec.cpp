/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergeVec.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:57:50 by emansoor          #+#    #+#             */
/*   Updated: 2024/12/18 13:47:02 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

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

void	PmergeMe::mergeVec(int level, int pairs)
{
	int		elem1;
	int		elem2;
	int		pair = 1;
	int		temp;
	double	N = pow(2, level);
	
	elem2 = N - 1;
	elem1 = 0;
	if (level != 1)
		elem1 = N - 1 - std::floor(N / 2);
	while (pair <= pairs)
	{
		if (_sortedVec[elem1] > _sortedVec[elem2])
		{
			if (level == 1)
			{
				temp = _sortedVec[elem1];
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
	if (pairs / 2 >= 1)
	{
		mergeVec(++level, pairs / 2);
		if (pairs > 2)
		{
			std::cout << "level: " << level << std::endl;
			std::cout << "pairs: " << pairs << std::endl;
			insertVec(level, pairs);
		}
	}
	else
	{
		std::cout << "og sequence: " << std::endl;
		for (int i = 1; _unsorted[i]; i++)
			std::cout << _unsorted[i] << " ";
		std::cout << std::endl;
		std::cout << "sorted sequence: " << std::endl;
		int i = 0;
		while (i < _size)
		{
			std::cout << _sortedVec[i] << " ";
			i++;
		}
		std::cout << std::endl;
	}
}

// even number:
// ./PmergeMe 1 3 15 8 14 7 10 5 11 12 13 4 9 0 2 6

// after level 1:
// 1 3 8 15 7 14 5 10 11 12 4 13 0 9 2 6

// after level 2:
// 1 3 8 15 5 10 7 14 11 12 4 13 2 6 0 9

// after level 3:
// 5 10 7 14 1 3 8 15 2 6 0 9 11 12 4 13

// after level 4:
// 2 6 0 9 11 12 4 13 5 10 7 14 1 3 8 15

// even but not enough:
// ./PmergeMe 19 10 1 17 12 13 3 21 8 15 4 18 0 9 11 6 7 14 5 16 2 20

// after level 1:
// 10 19 1 17 12 13 3 21 8 15 4 18 0 9 6 11 7 14 5 16 2 20

// after level 2:
// 1 17 10 19 12 13 3 21 8 15 4 18 0 9 6 11 7 14 5 16 2 20

// after level 3:
// 1 17 10 19 12 13 3 21 0 9 6 11 8 15 4 18 7 14 5 16 2 20

// after level 4:
// 0 9 6 11 8 15 4 18 1 17 10 19 12 13 3 21 7 14 5 16 2 20

// odd number:
// ./PmergeMe 0 2 1 8 5 4 14 9 10 7 3 6 13 11 12

// after level 1:
// 0 2 1 8 4 5 9 14 7 10 3 6 11 13 12

// after level 2:
// 0 2 1 8 4 5 9 14 3 6 7 10 11 13 12

// after level 3:
// 0 2 1 8 4 5 9 14 3 6 7 10 11 13 12

// 42 example: ./PmergeMe 11 2 17 0 16 8 6 15 10 3 21 1 18 9 14 19 12 5 4 20 13 7
