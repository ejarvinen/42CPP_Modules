/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertInt.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 12:50:24 by emansoor          #+#    #+#             */
/*   Updated: 2024/11/04 15:55:11 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* std::string	ScalarConverter::convertInt(std::string literal)
{
	int			nbr;
	std::string	res;

	try
	{
		nbr = stoi(literal);
	}
	catch (...)
	{
		return ("impossible");
	}
	res = std::to_string(nbr);
	return (res);
} */

int	ScalarConverter::convertInt(float flt, int *integer)
{
	if (flt > std::numeric_limits<int>::max() || flt < std::numeric_limits<int>::min())
		return (1);
	try
	{
		*integer = static_cast<int>(flt);
	}
	catch (...)
	{
		return (1);
	}
	return (0);
}
