/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:42:20 by emansoor          #+#    #+#             */
/*   Updated: 2024/11/09 15:07:44 by emansoor         ###   ########.fr       */
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
	char	chr = 0;
	int		integer = 0;
	float	flt = 0;
	double	dble = 0;
	
	if (inputChecker(literal) == false || convertDouble(literal, &dble))
	{
		std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;
		return ;
	}
	std::cout << std::fixed;
	if (decimals(literal) < 7)
		std::cout << std::setprecision(decimals(literal));
	else
		std::cout << std::setprecision(6);
	if (convertFloat(dble, &flt))
	{
		std::cout << "char: impossible\nint: impossible\nfloat: impossible" << std::endl;
		std::cout << "double: " << dble << std::endl;
		return ;
	}
	if (convertInt(dble, flt, &integer))
	{
		std::cout << "char: impossible\nint: impossible" << std::endl;
		std::cout << "float: " << flt << "f" << std::endl;
		std::cout << "double: " << dble << std::endl;
		return ;
	}
	if ((0 <= integer && integer < 32) || integer > 126)
	{
		std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << integer << std::endl;
		std::cout << "float: " << flt << "f" << std::endl;
		std::cout << "double: " << dble << std::endl;
		return ;
	}
	if (convertChr(integer, &chr))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: " << integer << std::endl;
		std::cout << "float: " << flt << "f" << std::endl;
		std::cout << "double: " << dble << std::endl;
		return ;
	}
	std::cout << "char: " << "'" << chr << "'" << std::endl;
	std::cout << "int: " << integer << std::endl;
	std::cout << "float: " << flt << "f" << std::endl;
	std::cout << "double: " << dble << std::endl;
}
