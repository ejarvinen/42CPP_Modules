/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:42:20 by emansoor          #+#    #+#             */
/*   Updated: 2024/11/03 12:50:16 by emansoor         ###   ########.fr       */
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

void	ScalarConverter::convert(std::string literal, ScalarConverter &obj)
{
	std::string	chr;
	std::string	integer;
	std::string	flt;
	std::string	dble;

	chr = obj.convertChr(literal);
	integer = obj.convertInt(literal);
	flt = obj.convertFloat(literal);
	dble = obj.convertDouble(literal);
	std::cout << "char: " << chr << std::endl;
	std::cout << "int: " << integer << std::endl;
	std::cout << "float: " << flt << std::endl;
	std::cout << "double: " << dble << std::endl;
}
