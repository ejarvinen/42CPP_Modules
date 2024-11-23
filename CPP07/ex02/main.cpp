/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:42:56 by emansoor          #+#    #+#             */
/*   Updated: 2024/11/23 12:44:01 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <string>

int main(void)
{
	Array<int>			intA(3);
	Array<std::string>	strA(3);

	std::cout << "size of intArray: " << intA.size() << std::endl;
	std::cout << "size of strArray: " << strA.size() << std::endl;

	for (int index = 0; index < 3; index++)
		intA[index] = index + 1;
	for (int index = 0; index < 3; index++)
		std::cout << "intArray[" << index << "]: " << intA[index] << std::endl;

	try
	{
		intA[3] = 4;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	strA[0] = "apple";
	strA[1] = "banana";
	strA[2] = "coconut";
	for (int index = 0; index < 3; index++)
		std::cout << "strArray[" << index << "]: " << strA[index] << std::endl;

	try
	{
		strA[3] = "lemon";
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	
	Array<std::string>	copyStrA(strA);
	std::cout << "copyStrArray[0] before: " << copyStrA[0] << std::endl;
	copyStrA[0] = "durian";
	for (int index = 0; index < 3; index++)
		std::cout << "copyStrArray[" << index << "]: " << copyStrA[index] << std::endl;

	for (int index = 0; index < 3; index++)
		std::cout << "strArray[" << index << "]: " << strA[index] << std::endl;
	
	std::cout << std::endl;
	
	Array<int>	copyIntA = intA;
	intA[2] = 4;
	std::cout << "intArray[2] after: " << intA[2] << std::endl;
	for (int index = 0; index < 3; index++)
		std::cout << "copyIntArray[" << index << "]: " << copyIntA[index] << std::endl;

	return (0);
}
