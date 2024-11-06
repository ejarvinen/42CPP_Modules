/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeConversions.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 12:49:47 by emansoor          #+#    #+#             */
/*   Updated: 2024/11/06 11:55:14 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	convertChr(int integer, char *chr)
{
	if (integer < 0)
		return (1);
	*chr = static_cast<char>(integer);
	return (0);
}

int	convertInt(double dble, float flt, int *integer)
{
	if (flt > (float)std::numeric_limits<int>::max() - 1.0
		|| flt <= (float)std::numeric_limits<int>::min()
		|| isnan(flt))
	{
		if (dble == (double)std::numeric_limits<int>::max()
			|| dble == (double)std::numeric_limits<int>::min()
			|| dble == (double)std::numeric_limits<int>::min() + 1)
		{
			*integer = static_cast<int>(dble);
			return (0);
		}
		return (1);
	}
	*integer = static_cast<int>(flt);
	return (0);
}

int	convertFloat(double dble, float *flt)
{
	if (dble > (double)std::numeric_limits<float>::max()
		|| dble < (-1.0) * (double)std::numeric_limits<float>::max())
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
	*flt = static_cast<float>(dble);
	return (0);
}

int	convertDouble(std::string literal, double *dble)
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
