/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeConversions.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 12:49:47 by emansoor          #+#    #+#             */
/*   Updated: 2024/11/18 11:45:12 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	convertChr(std::string literal)
{
	char	chr;
	int		integer;
	float	flt;
	double	dble;

	if (literal.length() == 1)
		chr = static_cast<char>(literal[0]);
	else
		chr = static_cast<char>(literal[1]);
	if (chr > 126)
		std::cout << "char: impossible" << std::endl;
	else if (0 <= chr && chr < 32)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << "'" << chr << "'" << std::endl;
	integer = static_cast<int>(chr);
	flt = static_cast<float>(chr);
	dble = static_cast<double>(chr);
	std::cout << "int: " << integer << std::endl;
	std::cout << "float: " << flt << "f" << std::endl;
	std::cout << "double: " << dble << std::endl;
	return (0);
}

int	convertInt(std::string literal)
{
	char	chr;
	int		integer;
	float 	flt;
	double	dble;

	try
	{
		integer = stoi(literal);
	}
	catch (std::invalid_argument const &ex)
	{
		return (convertFloat(literal));
	}
	catch (std::out_of_range const &ex)
	{
		return (convertFloat(literal));
	}
	if (integer < 0 || integer > 126)
		std::cout << "char: impossible" << std::endl;
	else if (0 <= integer && integer < 32)
		std::cout << "char: Non displayable" << std::endl;
	else
	{
		chr = static_cast<char>(integer);
		std::cout << "char: " << "'" << chr << "'" << std::endl;
	}
	flt = static_cast<float>(integer);
	dble = static_cast<double>(integer);
	std::cout << "int: " << integer << std::endl;
	std::cout << "float: " << flt << "f" << std::endl;
	std::cout << "double: " << dble << std::endl;
	return (0);
}

int	convertFloat(std::string literal)
{
	char	chr;
	int		integer;
	float 	flt;
	double	dble;

	try
	{
		flt = stof(literal);
	}
	catch (std::out_of_range const &ex)
	{
		return (convertDouble(literal));
	}
	if (flt > (float)std::numeric_limits<int>::max() - 1.0
		|| flt <= (float)std::numeric_limits<int>::min()
		|| isnan(flt))
	{
		dble = static_cast<double>(flt);
		std::cout << "char: impossible\nint: impossible" << std::endl;
		std::cout << "float: " << flt << "f" << std::endl;
		std::cout << "double: " << dble << std::endl;
		return (0);
	}
	chr = static_cast<char>(flt);
	integer = static_cast<int>(flt);
	dble = static_cast<double>(flt);
	if (chr < 0 || chr > 126)
		std::cout << "char: impossible" << std::endl;
	else if (0 <= chr && chr < 32)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << "'" << chr << "'" << std::endl;
	std::cout << "int: " << integer << std::endl;
	std::cout << "float: " << flt << "f" << std::endl;
	std::cout << "double: " << dble << std::endl;
	return (0);
}

int	convertDouble(std::string literal)
{
	char	chr;
	int		integer;
	float 	flt;
	double	dble;

	try
	{
		dble = stod(literal);
	}
	catch (std::out_of_range const &ex)
	{
		return (1);
	}
	if (dble > (double)std::numeric_limits<float>::max()
		|| dble < (-1.0) * (double)std::numeric_limits<float>::max())
	{
		if (isinf(dble))
		{
			if (dble < 0)
				flt = (-1) * std::numeric_limits<float>::infinity();
			else
				flt = std::numeric_limits<float>::infinity();
			std::cout << "char: impossible\nint: impossible" << std::endl;
			std::cout << "float: " << flt << std::endl;
			std::cout << "double: " << dble << std::endl;
			return (0);
		}
		std::cout << "char: impossible\nint: impossible\nfloat: impossible" << std::endl;
		std::cout << "double: " << dble << std::endl;
		return (0);
	}
	flt = static_cast<float>(dble);
	if (dble > (double)std::numeric_limits<int>::max()
		|| dble < (double)std::numeric_limits<int>::min()
		|| isnan(dble))
	{
		std::cout << "char: impossible\nint: impossible" << std::endl;
		std::cout << "float: " << flt << "f" << std::endl;
		std::cout << "double: " << dble << std::endl;
		return (0);
	}
	integer = static_cast<int>(dble);
	chr = static_cast<char>(dble);
	if (chr < 0 || chr > 126)
		std::cout << "char: impossible" << std::endl;
	else if (0 <= chr && chr < 32)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << "'" << chr << "'" << std::endl;
	std::cout << "int: " << integer << std::endl;
	std::cout << "float: " << flt << "f" << std::endl;
	std::cout << "double: " << dble << std::endl;
	return (0);
}
