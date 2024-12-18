/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertVec.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:45:29 by emansoor          #+#    #+#             */
/*   Updated: 2024/12/18 14:22:28 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	PmergeMe::insertVec(int level, int pairs)
{
	std::vector<int>	pend;
	std::vector<int>	main;
	std::vector<int>	pendIndexes;
	std::vector<int>	oddb;
	int					pair = 1;
	int					i;
	int					elem;
	bool				odd = false;
	double				N = pow(2, level);

	if (pairs % 2 != 0)
	{
		odd = true;
		pairs--;
	}
	while (pair <= pairs)
	{
		if (pair != 1 && pair % 2 != 0)
		{
			elem = (pair - 1) * N / 2;
			pendIndexes.push_back(elem);
			i = 0;
			while (i < N / 2)
			{
				pend.push_back(_sortedVec[elem + i]);
				i++;
			}
		}
		else
		{
			if (pair == 1)
			{
				i = 0;
				while (i < N)
				{
					main.push_back(_sortedVec[i]);
					i++;
				}
			}
			else if (pair > 2)
			{
				elem = (pair - 1) * (N / 2);
				i = 0;
				while (i < N / 2)
				{
					main.push_back(_sortedVec[elem + i]);
					i++;
				}
			}
		}
		pair++;
	}
	if (odd)
	{
		elem = pairs * (N / 2);
		i = 0;
		while (i < N / 2)
		{
			oddb.push_back(_sortedVec[elem + i]);
			i++;
		}
	}

	std::cout << "og: ";
	for (int j = 0; _sortedVec[j]; j++)
		std::cout << _sortedVec[j] << " ";
	std::cout << std::endl;
	
	std::cout << "main: ";
	for (int j = 0; main[j]; j++)
		std::cout << main[j] << " ";
	std::cout << std::endl;

	std::cout << "pend: ";
	for (int j = 0; pend[j]; j++)
		std::cout << pend[j] << " ";
	std::cout << std::endl;
	
	std::cout << "indexes: ";
	for (int j = 0; pendIndexes[j]; j++)
		std::cout << pendIndexes[j] << " ";
	std::cout << std::endl;

	if (odd)
	{
		std::cout << "odd: ";
		for (int j = 0; oddb[j]; j++)
			std::cout << oddb[j] << " ";
		std::cout << std::endl;
	}
}