/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:21:17 by emansoor          #+#    #+#             */
/*   Updated: 2024/11/11 10:35:50 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	Data		*ptr = new Data;
	Data		*newPtr = nullptr;
	uintptr_t	dataholder = 0;

	(*ptr)._dataInt = 3;
	(*ptr)._dataStr = "Hello World";
	
	std::cout << "Address of Data object: " << &ptr << std::endl;
	std::cout << "Data *ptr address: " << ptr << std::endl;
	std::cout << "Int stored in Data: " << (*ptr)._dataInt << std::endl;
	std::cout << "String stored in Data: " << (*ptr)._dataStr << std::endl;
	std::cout << "Number of bytes taken by Data struct: " << sizeof(*ptr) << std::endl;
	std::cout << "Number of bytes taken by Data *ptr: " << sizeof(ptr) << std::endl;
	std::cout << "dataholder's value before serialize: " << dataholder << std::endl;
	
	std::cout << "**********" << std::endl;
	dataholder = Serializer::serialize(ptr);
	if (dataholder)
	{
		std::cout << "dataholder's value after serialize: " << dataholder << std::endl;
		std::cout << "dataholder's address: " << &dataholder << std::endl;
		std::cout << "Number of bytes taken by dataholder: " << sizeof(dataholder) << std::endl;
	}
	else
	{
		delete (ptr);
		return (1);
	}
	
	std::cout << "Data *newPtr address before deserialize: " << newPtr << std::endl;
	std::cout << "**********" << std::endl;
	newPtr = Serializer::deserialize(dataholder);
	if (newPtr)
	{
		std::cout << "Data *newPtr address after deserialize: " << newPtr << std::endl;
		std::cout << "Int stored in *newPtr's struct: " << (*newPtr)._dataInt << std::endl;
		std::cout << "String stored in *newPtr's struct: " << (*newPtr)._dataStr << std::endl;
		std::cout << "Number of bytes taken by Data struct in *newPtr: " << sizeof(*newPtr) << std::endl;
		std::cout << "Number of bytes taken by Data *newPtr: " << sizeof(newPtr) << std::endl;
		delete (ptr);
		return (0);
	}
	delete (ptr);
	return (1);
}
