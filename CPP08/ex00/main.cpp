/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:41:53 by emansoor          #+#    #+#             */
/*   Updated: 2024/11/24 14:05:28 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <array>
#include <vector>
#include <deque>
#include <forward_list>
#include <list>

int	main(void)
{
	std::array<int, 5> ar = {1, 2, 3, 4, 5};
	std::vector<int> ve = {1, 2, 3, 4, 5};
	std::deque<int> de = {1, 2, 3, 4, 5};
	std::forward_list<int> fo = {1, 2, 3, 4, 5};
	std::list<int> li = {1, 2, 3, 4, 5};

	easyfind(ar, 1);
	easyfind(ve, 2);
	easyfind(de, 3);
	easyfind(fo, 4);
	easyfind(li, 5);

	try
	{
		easyfind(de, 0);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::vector<int> emptyVector;
	try
	{
		easyfind(emptyVector, 123);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::list<int> uniformList = {1, 1, 1, 1, 1};
	easyfind(uniformList, 1);
	
	return (0);
}