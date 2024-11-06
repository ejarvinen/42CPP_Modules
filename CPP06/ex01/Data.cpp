/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractClass.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:11:43 by emansoor          #+#    #+#             */
/*   Updated: 2024/11/06 12:15:44 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbstractClass.hpp"

AbstractClass::AbstractClass() {}

AbstractClass::AbstractClass(AbstractClass const &copy)
{
	*this = copy;
}

AbstractClass::~AbstractClass() {}

AbstractClass	&AbstractClass::operator=(AbstractClass const &other)
{
	if (this != &other)
	{}
	return (*this);
}
