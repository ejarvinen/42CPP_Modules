/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DerivedClass.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:16:06 by emansoor          #+#    #+#             */
/*   Updated: 2024/11/06 12:20:18 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DerivedClass.hpp"

DerivedClass::DerivedClass() : AbstractClass() {}

DerivedClass::DerivedClass(DerivedClass const &copy)
{
	*this = copy;
}

DerivedClass::~DerivedClass() {}

DerivedClass	&DerivedClass::operator=(DerivedClass const &other)
{
	if (this != &other)
	{}
	return (*this);
}

void	DerivedClass::printAddress()
{
	std::cout << "DerivedClass object address: " << this << std::endl;
}
