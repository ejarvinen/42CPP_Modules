/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:42:56 by emansoor          #+#    #+#             */
/*   Updated: 2024/11/22 11:08:48 by emansoor         ###   ########.fr       */
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

	intA[0] = 1;
	intA[1] = 2;
	intA[2] = 3;
	std::cout << "intArray[0]: " << intA[0] << std::endl;
	std::cout << "intArray[1]: " << intA[1] << std::endl;
	std::cout << "intArray[2]: " << intA[2] << std::endl;

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
	std::cout << "strArray[0]: " << strA[0] << std::endl;
	std::cout << "strArray[1]: " << strA[1] << std::endl;
	std::cout << "strArray[2]: " << strA[2] << std::endl;

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
	std::cout << "copyStrArray[0] after: " << copyStrA[0] << std::endl;
	std::cout << "copyStrArray[1]: " << copyStrA[1] << std::endl;
	std::cout << "copyStrArray[2]: " << copyStrA[2] << std::endl;
	std::cout << "strArray[0]: " << strA[0] << std::endl;
	
	std::cout << std::endl;
	
	Array<int>	copyIntA = intA;
	intA[2] = 4;
	std::cout << "intArray[2] after: " << intA[2] << std::endl;
	std::cout << "copyIntArray[0]: " << copyIntA[0] << std::endl;
	std::cout << "copyIntArray[1]: " << copyIntA[1] << std::endl;
	std::cout << "copyIntArray[2]: " << copyIntA[2] << std::endl;

	return (0);
}
