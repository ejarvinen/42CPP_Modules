/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:21:14 by emansoor          #+#    #+#             */
/*   Updated: 2024/11/07 11:38:06 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::~Serializer() {}

Serializer::Serializer(Serializer const &copy)
{
	*this = copy;
}

Serializer	&Serializer::operator=(Serializer const &other)
{
	if (this != &other)
	{}
	return (*this);
}

uintptr_t	Serializer::serialize(Data *ptr)
{
	uintptr_t	dataHolder = 0;

	if (ptr)
	{
		try
		{
			dataHolder = reinterpret_cast<uintptr_t>(ptr);
		}
		catch (...)
		{
			std::cout << "Reinterpret_cast failed" << std::endl;
			return (0);
		}
	}
	return (dataHolder);
}

Data	*Serializer::deserialize(uintptr_t raw)
{
	Data	*ptr = nullptr;

	try
	{
		ptr = reinterpret_cast<Data*>(raw);
	}
	catch (...)
	{
		std::cout << "Reinterpret_cast failed" << std::endl;
	}
	return (ptr);
}
