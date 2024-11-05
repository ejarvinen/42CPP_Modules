/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeConversions.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 12:49:47 by emansoor          #+#    #+#             */
/*   Updated: 2024/11/05 11:52:20 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	ScalarConverter::convertChr(int integer, char *chr)
{
	if (integer > 126 || integer < 0)
		return (1);
	try
	{
		*chr = static_cast<char>(integer);
	}
	catch (...)
	{
		return (1);
	}
	return (0);
}

int	ScalarConverter::convertInt(float flt, int *integer)
{
	if (flt > (float)2147483647 || flt < std::numeric_limits<int>::min() || isnan(flt))
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

int	ScalarConverter::convertFloat(double dble, float *flt)
{
	if (dble > std::numeric_limits<float>::max() || dble < (-1) * std::numeric_limits<float>::max())
	{
		if (isinf(dble))
		{
			if (dble < 0)
				*flt = (-1) * std::numeric_limits<float>::infinity();
			else
				*flt = std::numeric_limits<float>::infinity();
			return (0);
		}
		return (1);
	}
	try
	{
		*flt = static_cast<float>(dble);
	}
	catch (...)
	{
		return (1);
	}
	return (0);
}

int	ScalarConverter::convertDouble(std::string literal, double *dble)
{
	try
	{
		*dble = stod(literal);
	}
	catch (...)
	{
		return (1);
	}
	return (0);
}
