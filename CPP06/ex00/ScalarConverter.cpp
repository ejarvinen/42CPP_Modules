/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:42:20 by emansoor          #+#    #+#             */
/*   Updated: 2024/11/02 15:55:52 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &copy)
{
	*this = copy;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter	&ScalarConverter::operator=(ScalarConverter const &other)
{
	if (this != &other)
	{}
	return (*this);
}

std::string	ScalarConverter::convertChr(std::string const literal)
{
	int			chr;
	char		ch;
	std::string	res = "'";

	try
	{
		chr = stoi(literal);
		if (chr < 32 || chr > 126)
		{
			if (chr > 126)
				return ("impossible");
			return ("Non displayable");
		}
	}
	catch (...)
	{
		if (literal.length() == 1)
		{
			res = res + literal;
			res.append("'");
			return (res);
		}
		return ("impossible");
	}
	try
	{
		ch = static_cast<char>(chr);
	}
	catch (...)
	{
		return ("Static cast failed");
	}
	res = res + ch;
	res.append("'");
	return (res);
}

std::string	ScalarConverter::convertInt(std::string literal)
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
}

std::string	ScalarConverter::floatDecimalHandler(std::string literal, std::string res, size_t pointIndex)
{
	int			decim;
	int			lastDecim;
	int			toBeRounded;
	size_t		index;
	char		chr;
	
	decim = 1;
	index = pointIndex;
	for (index++; std::isdigit(literal[index]) != 0; index++)
		decim++;
	if (decim < 7)
	{
		lastDecim = static_cast<int>(res[pointIndex + decim]) - 48;
		res = res.substr(0, pointIndex + decim);
		toBeRounded = static_cast<int>(res[res.length() - 1]) - 48;
		if (toBeRounded < lastDecim)
		{
			toBeRounded++;
			chr = static_cast<char>(toBeRounded) + 48;
			res.replace(res.length() - 1, 1, 1, chr);
		}
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

void	ScalarConverter::convert(std::string literal, ScalarConverter &obj)
{
	std::string	chr;
	std::string	integer;
	std::string	flt;
	std::string	dble;

	chr = obj.convertChr(literal);
	integer = obj.convertInt(literal);
	flt = obj.convertFloat(literal);
	//dble = obj.convertDouble(literal);
	std::cout << "char: " << chr << std::endl;
	std::cout << "int: " << integer << std::endl;
	std::cout << "float: " << flt << std::endl;
	//std::cout << "double: " << dble << std::endl;
}
