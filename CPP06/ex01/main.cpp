/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:21:17 by emansoor          #+#    #+#             */
/*   Updated: 2024/11/07 12:17:33 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int	main(void)
{
	Data		*ptr = new Data(3);
	Data		*newPtr = nullptr;
	uintptr_t	dataholder;
	
	std::cout << "Address of Data object: " << &ptr << std::endl;
	std::cout << "Data *ptr address: " << ptr << std::endl;
	std::cout << "Value stored in Data: " << ptr->getInt() << std::endl;
	std::cout << "Number of bytes taken by Data object: " << sizeof(*ptr) << std::endl;
	std::cout << "Number of bytes taken by Data *ptr: " << sizeof(ptr) << std::endl;
	
	dataholder = Serializer::serialize(ptr);
	if (dataholder)
	{
		std::cout << "dataholder's value after serialize: " << dataholder << std::endl;
		std::cout << "dataholder's address: " << &dataholder << std::endl;
		std::cout << "Number of bytes taken by dataholder: " << sizeof(dataholder) << std::endl;
	}
	else
		return (1);
	
	newPtr = Serializer::deserialize(dataholder);
	if (newPtr)
	{
		std::cout << "Data *newPtr address: " << newPtr << std::endl;
		std::cout << "Value stored in newPtr's object: " << newPtr->getInt() << std::endl;
		std::cout << "Number of bytes taken by Data object: " << sizeof(*newPtr) << std::endl;
		std::cout << "Number of bytes taken by Data *newPtr: " << sizeof(ptr) << std::endl;
		delete (ptr);
		return (0);
	}
	delete (ptr);
	return (1);
}
