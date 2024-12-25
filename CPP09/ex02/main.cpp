/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:09:26 by emansoor          #+#    #+#             */
/*   Updated: 2024/12/23 18:10:18 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cout << "Error: not enough arguments" << std::endl;
		return (1);
	}
	PmergeMe	pmergeMe;
	pmergeMe.sortNums(argv);
	return (0);
}

