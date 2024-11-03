/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertFnD.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 12:49:47 by emansoor          #+#    #+#             */
/*   Updated: 2024/11/03 12:50:09 by emansoor         ###   ########.fr       */
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
	if (decim < 8)
	{
		res = rounder(res, pointIndex, decim);
	}
	return (res);
}

std::string	ScalarConverter::convertFloat(std::string literal)
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
	res = std::to_string(nbrFloat);
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
	res = res + 'f';
	return (res);
}

std::string	ScalarConverter::doubleDecimalHandler(std::string literal, std::string res, size_t pointIndex)
{
	int		decim;
	size_t	index;
	
	decim = 1;
	index = pointIndex;
	for (index++; std::isdigit(literal[index]) != 0; index++)
		decim++;
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

std::string	ScalarConverter::convertDouble(std::string literal)
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
}
