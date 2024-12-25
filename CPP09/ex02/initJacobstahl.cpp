/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initJacobstahl.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 17:51:46 by emansoor          #+#    #+#             */
/*   Updated: 2024/12/25 17:52:06 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

double PmergeMe::jacobstahl(double n)
{
    if (n == 0)
        return (0);
    if (n == 1)
        return (1);
    return (jacobstahl(n - 1) + 2 * jacobstahl(n - 2));
}

void	PmergeMe::initJacobstahl(void)
{
	int		index = 0;
	double	jNum = 0;

	jNum = jacobstahl(index);
	while (jNum <= (double)_size)
	{
		_jNums.push_back(jNum);
		index++;
		jNum = jacobstahl(index);
	}
	_jNums.push_back(jNum);
}
