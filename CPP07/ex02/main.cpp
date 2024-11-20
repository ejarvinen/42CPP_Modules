/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:42:56 by emansoor          #+#    #+#             */
/*   Updated: 2024/11/20 15:56:02 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <string>

int main(void)
{
	Array<int>			intA(3);
	Array<std::string>	strA(5);

	std::cout << "size of intArray: " << intA.size() << std::endl;
	std::cout << "size of strArray: " << strA.size() << std::endl;

	intA[0] = 1;
	intA[1] = 2;
	std::cout << intA[0] << std::endl;
	std::cout << intA[1] << std::endl;

	strA[0] = "apple";
	strA[1] = "banana";
	std::cout << strA[0] << std::endl;
	std::cout << strA[1] << std::endl;

	try
	{
		strA[6] = "lemon";
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
