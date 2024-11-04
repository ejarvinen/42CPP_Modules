/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertFnD.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 12:49:47 by emansoor          #+#    #+#             */
/*   Updated: 2024/11/04 15:26:40 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

std::string	ScalarConverter::rounder(std::string res, size_t pointIndex, int decim)
{
	int		lastDecim;
	int		toBeRounded;
	char	chr;
	
	try
	{
		lastDecim = static_cast<int>(res[pointIndex + decim]) - 48;
	}
	catch (...)
	{
		return ("Static cast failed");
	}
	res = res.substr(0, pointIndex + decim);
	try
	{
		toBeRounded = static_cast<int>(res[res.length() - 1]) - 48;
	}
	catch (...)
	{
		return ("Static cast failed");
	}
	if (toBeRounded < lastDecim)
	{
		toBeRounded++;
		try
		{
			chr = static_cast<char>(toBeRounded) + 48;
		}
		catch (...)
		{
			return ("Static cast failed");
		}
		res.replace(res.length() - 1, 1, 1, chr);
	}
	return (res);
}

std::string	ScalarConverter::floatDecimalHandler(std::string literal, std::string res, size_t pointIndex)
{
	int			decim;
	size_t		index;
	
	decim = 1;
	index = pointIndex;
	for (index++; std::isdigit(literal[index]) != 0; index++)
		decim++;
	if (decim < 2)
		return ("impossible");
	if (decim < 8)
	{
		res = rounder(res, pointIndex, decim);
	}
	return (res);
}

int	ScalarConverter::convertFloat(double dble, float *flt)
{
	if (dble > std::numeric_limits<float>::max() || dble < std::numeric_limits<float>::min())
		return (1);
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

/* std::string	ScalarConverter::convertFloat(std::string literal)
{
	float		nbrFloat;
	size_t		pointIndex;
	std::string	res;

	try
	{
		nbrFloat = stof(literal);
	}
	catch (...)
	{
		return ("impossible");
	}
	std::cout << std::setprecision(15);
	std::cout << nbrFloat << std::endl;
	res = std::to_string(nbrFloat);
	std::cout << res << std::endl;
	pointIndex = literal.find(".");
	if (pointIndex != std::string::npos)
	{
		res = floatDecimalHandler(literal, res, pointIndex);
	}
	else
	{
		pointIndex = res.find('.');
		res = res.erase(pointIndex + 2);
	}
	if (res.compare("impossible") != 0)
		res = res + 'f';
	return (res);
} */

std::string	ScalarConverter::doubleDecimalHandler(std::string literal, std::string res, size_t pointIndex)
{
	int		decim;
	size_t	index;
	
	decim = 1;
	index = pointIndex;
	for (index++; std::isdigit(literal[index]) != 0; index++)
		decim++;
	if (decim < 2)
		return ("impossible");
	if (decim < 8)
	{
		res = rounder(res, pointIndex, decim);
	}
	else
	{
		for (index = pointIndex + 7; index < 15 && std::isdigit(literal[index]) != 0; index++)
			res = res + literal[index];
	}
	return (res);
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

/* std::string	ScalarConverter::convertDouble(std::string literal)
{
	double		nbrDouble;
	size_t		pointIndex;
	std::string	res;

	try
	{
		nbrDouble = stod(literal);
	}
	catch (...)
	{
		return ("impossible");
	}
	res = std::to_string(nbrDouble);
	pointIndex = literal.find(".");
	if (pointIndex != std::string::npos)
	{
		res = doubleDecimalHandler(literal, res, pointIndex);
	}
	else
	{
		pointIndex = res.find('.');
		res = res.erase(pointIndex + 2);
	}
	return (res);
} */
