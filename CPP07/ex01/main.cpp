/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:59:32 by emansoor          #+#    #+#             */
/*   Updated: 2024/11/22 16:37:27 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <string>

int	main(void)
{
	int	nums[] = {1, 2, 3, 4, 5};
	std::string	fruits[] = {"apple", "banana", "coconut", "durian", "elderberry"};
	
	iter(nums, 5, printMember<const int>);
	iter(nums, 5, increment<int>);
	std::cout << std::endl;
	iter(nums, 5, printMember<const int>);
	
	std::cout << std::endl;
	
	iter(fruits, 5, printMember<const std::string>);

	return (0);
}
