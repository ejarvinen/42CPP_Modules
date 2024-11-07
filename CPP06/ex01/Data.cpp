/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:11:43 by emansoor          #+#    #+#             */
/*   Updated: 2024/11/07 11:51:03 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : _dataInt(0) {}

Data::Data(int dataInt) : _dataInt(dataInt) {}

Data::Data(Data const &copy)
{
	*this = copy;
}

Data::~Data() {}

Data	&Data::operator=(Data const &other)
{
	if (this != &other)
	{
		_dataInt = other._dataInt;
	}
	return (*this);
}

int	Data::getInt()
{
	return (_dataInt);
}
