/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:09:26 by emansoor          #+#    #+#             */
/*   Updated: 2024/12/17 14:50:20 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cout << "Error: no enough arguments" << std::endl;
		return (1);
	}
	PmergeMe	pmergeMe;
	pmergeMe.sortNums(argv);
	return (0);
}

