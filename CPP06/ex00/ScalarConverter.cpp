/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:42:20 by emansoor          #+#    #+#             */
/*   Updated: 2024/11/04 15:58:36 by emansoor         ###   ########.fr       */
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

bool	ScalarConverter::isValidChr(int c)
{
	return (std::isdigit(c) || c == '.' || c == 'f' || c == '-' || c == '+');
}

bool	ScalarConverter::inputChecker(std::string literal)
{
	int	index;
	int	points = 0;

	for (index = 0; literal[index]; index++)
	{
		if (isValidChr(literal[index]))
		{
			if (literal[index] == '.')
				points++;
			if ((literal[index] == 'f' && literal[index + 1])
				|| (literal[index] == '+' && index > 0)
				|| (literal[index] == '-' && index > 0)
				|| points > 1)
				return (false);
		}
		else
			return (false);
	}
	return (true);
}

void	ScalarConverter::print(std::string chr, std::string integer, std::string flt, std::string dble)
{
	std::cout << "char: " << chr << std::endl;
	std::cout << "int: " << integer << std::endl;
	std::cout << "float: " << flt << std::endl;
	std::cout << "double: " << dble << std::endl;
}

int	ScalarConverter::handleSpecialCase(std::string literal)
{
	if (!literal.compare("nan"))
	{
		print("impossible", "impossible", "nanf", literal);
		return (1);
	}
	if (!literal.compare("+inf"))
	{
		print("impossible", "impossible", "+inff", literal);
		return (1);
	}
	if (!literal.compare("-inf"))
	{
		print("impossible", "impossible", "-inff", literal);
		return (1);
	}
	if (!literal.compare("nanf"))
	{
		print("impossible", "impossible", literal, "nan");
		return (1);
	}
	if (!literal.compare("+inff"))
	{
		print("impossible", "impossible", literal, "+inf");
		return (1);
	}
	if (!literal.compare("-inff"))
	{
		print("impossible", "impossible", literal, "-inf");
		return (1);
	}
	return (0);
}

void	ScalarConverter::convert(std::string literal, ScalarConverter &obj)
{
	char	chr;
	int		integer;
	float	flt;
	double	dble;
	
	if (obj.inputChecker(literal) == false)
	{
		if (!obj.handleSpecialCase(literal))
			return (obj.print("impossible", "impossible", "impossible", "impossible"));
		return ;
	}
	if (obj.convertDouble(literal, &dble))
	{
		return (obj.print("impossible", "impossible", "impossible", "impossible"));
	}
	if (obj.convertFloat(dble, &flt))
	{
		std::cout << "char: impossible\nint: impossible\nfloat: impossible" << std::endl;
		std::cout << "double: " << dble << std::endl;
		return ;
	}
	if (obj.convertInt(flt, &integer))
	{
		std::cout << "char: impossible\nint: impossible" << std::endl;
		std::cout << "float: " << flt << std::endl;
		std::cout << "double: " << dble << std::endl;
		return ;
	}
	if (obj.convertChr(integer, &chr))
	{
		
	}
}

/* void	ScalarConverter::convert(std::string literal, ScalarConverter &obj)
{
	std::string	chr;
	std::string	integer;
	std::string	flt;
	std::string	dble;
	
	if (obj.inputChecker(literal) == false)
	{
		if (!obj.handleSpecialCase(literal))
			return (obj.print("impossible", "impossible", "impossible", "impossible"));
		return ;
	}
	dble = obj.convertDouble(literal);
	if (dble.compare("impossible") == 0)
	{
		return (obj.print("impossible", "impossible", "impossible", dble));
	}
	flt = obj.convertFloat(literal);
	if (flt.compare("impossible") == 0)
	{
		return (obj.print("impossible", "impossible", flt, dble));
	}
	integer = obj.convertInt(literal);
	if (integer.compare("impossible") == 0)
	{
		return (obj.print("impossible", integer, flt, dble));
	}
	chr = obj.convertChr(literal);
	obj.print(chr, integer, flt, dble);
} */
