/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:42:20 by emansoor          #+#    #+#             */
/*   Updated: 2024/11/18 11:49:01 by emansoor         ###   ########.fr       */
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

void	ScalarConverter::convert(std::string literal)
{
	int		status = -1;
	bool	charType = false;
	
	charType = charCheck(literal);
	if (literal.empty() || (!inputChecker(literal) && !charType))
	{
		std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;
		return ;
	}
	std::cout << std::fixed;
	if (decimals(literal) < 7)
		std::cout << std::setprecision(decimals(literal));
	else
		std::cout << std::setprecision(6);
	if (charType)
	{
		status = convertChr(literal);
	}
	else if (status != 0 && literal.find("f") != std::string::npos)
	{
		status = convertFloat(literal);
	}
	else if (status != 0 && literal.find(".") != std::string::npos)
	{
		status = convertDouble(literal);
	}
	else if (status != 0)
	{
		status = convertInt(literal);
	}
}
