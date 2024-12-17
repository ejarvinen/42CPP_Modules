/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:57:50 by emansoor          #+#    #+#             */
/*   Updated: 2024/12/17 15:31:10 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	PmergeMe::arrangePairs(int elem1, int elem2, int N)
{
	std::vector<int>			temp;
	std::vector<int>::iterator	it;
	int							i = elem2 - N;

	std::advance(elem2, (-1) * (N - 1));
	while (i < elem2)
	{
		temp.push_back(_sortedVec[elem2]);
		std::advance(elem2, 1);
		i++;
	}
	i = N / 2;
	while (i > 0)
	{
		
	}

	

	std::cout << "N: " << N << std::endl;
	std::cout << "e1: " << *elem1 << std::endl;
	std::cout << "e2: " << *elem2 << std::endl;
}

void	PmergeMe::sortVec(int level, int pairs)
{
	int	elem1;
	int	elem2;
	int							pair = 1;
	int							temp;
	double						N = pow(2, level);
	
	elem2 = N - 1;
	elem1 = 0;
	if (level != 1)
		elem1 = N - 1 - std::floor(N / 2);
	std::cout << "level " << level << std::endl;
	while (pair <= pairs)
	{
		std::cout << "elem1: " << _sortedVec[elem1] << std::endl;
		std::cout << "elem2: " << _sortedVec[elem2] << std::endl;
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
		level++;
		sortVec(level, pairs / 2);
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

/* void	PmergeMe::sortVec(int level, int pairs)
{
	std::vector<int>::iterator	elem1;
	std::vector<int>::iterator	elem2;
	int							pair = 1;
	int							temp;
	double						N = pow(2, level);
	

	elem1 = _sortedVec.begin();
	elem2 = elem1;
	std::advance(elem2, N - 1);
	if (level != 1)
		std::advance(elem1, N - 1 - std::floor(N / 2));
	std::cout << "level " << level << std::endl;
	while (pair <= pairs)
	{
		std::cout << "elem1: " << *elem1 << std::endl;
		std::cout << "elem2: " << *elem2 << std::endl;
		if (*elem1 > *elem2)
		{
			if (level == 1)
			{
				temp = *elem1;
				*elem1 = *elem2;
				*elem2 = temp;
			}
			else
			{
				//arrangePairs(elem1, elem2, N);
			}
		}
		std::advance(elem2, N);
		elem1 = elem2;
		std::advance(elem1, (-1) * std::floor(N / 2));
		pair++;
	}
	if (pairs / 2 >= 1)
	{
		level++;
		sortVec(level, pairs / 2);
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
} */

// ./PmergeMe 1 3 15 8 14 7 10 5 11 12 13 4 9 0 2 6

// after level 1:
// 1 3 8 15 7 14 5 10 11 12 4 13 0 9 2 6

// after level 2:
// 1 3 8 15 5 10 7 14 11 12 4 13 2 6 0 9

// after level 3:
// 5 10 7 14 1 3 8 15 2 6 0 9 11 12 4 18

// after level 4:
// - || -
