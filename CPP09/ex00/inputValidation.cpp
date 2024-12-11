/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputValidation.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:05:02 by emansoor          #+#    #+#             */
/*   Updated: 2024/12/11 15:59:32 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool	BitcoinExchange::isValidDate(std::string *date)
{
	int	y;
	int	m;
	int	d;

	y = std::stoi(*date);
	if (y < 2009)
	{
		std::cout << "Error: invalid year." << std::endl;
		return (false);
	}
	m = std::stoi((*date).substr(5, 7));
	if (m < 1 || m > 12)
	{
		std::cout << "Error: invalid month." << std::endl;
		return (false);
	}
	d = std::stoi((*date).substr(8, std::string::npos));
	if (d < 1 || d > 31)
	{
		std::cout << "Error: invalid day." << std::endl;
		return (false);
	}
	if ((d == 31 && (m == 2 || m == 4 || m == 6 || m == 9 || m == 11))
		|| (m == 2 && d == 29 && !isLeapYear(*date)) || (m == 2 && d == 30))
	{
		std::cout << "Error: date doesn't exist." << std::endl;
		return (false);
	}
	if ((d == 1 && m == 1 && y == 2009) || isFuture(date))
	{
		std::cout << "Error: invalid date." << std::endl;
		return (false);
	}
	return (true);
}

bool	BitcoinExchange::checkIntValue(std::string *value)
{
	int	val;
	
	try
	{
		val = std::stoi(*value);
	}
	catch (const std::exception& e)
	{
		if (value[0] == "-")
			std::cout << "Error: not a positive number." << std::endl;
		else
			std::cout << "Error: too large a number." << std::endl;
		return (false);
	}
	if (val > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return (false);
	}
	else if (val < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return (false);
	}
	return (true);
}

bool	BitcoinExchange::isValidValue(std::string *value)
{
	float	val;

	if ((*value).find('.') != std::string::npos)
	{
		try
		{
			val = std::stof(*value);
		}
		catch (const std::exception& e)
		{
			if (value[0] == "-")
				std::cout << "Error: not a positive number." << std::endl;
			else
				std::cout << "Error: too large a number." << std::endl;
			return (false);
		}
		if (val > 1000.0)
		{
			std::cout << "Error: too large a number." << std::endl;
			return (false);
		}
		else if (val < 0.0)
		{
			std::cout << "Error: not a positive number." << std::endl;
			return (false);
		}
		return (true);
	}
	return (checkIntValue(value));
}

int	BitcoinExchange::isValidLine(std::string line, std::string *date, std::string *value)
{
	std::size_t	delim;
	std::regex d("[0-9]{4}-[0-9]{2}-[0-9]{2}");
	std::regex v("[+-]?[0-9]*[.]?[0-9]+");

	delim = line.find(" | ");
	if (delim == std::string::npos)
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return (1);
	}
	*date = line.substr(0, delim);
	*value = line.substr(delim + 3, std::string::npos);
	if (std::regex_match(*date, d))
	{
		if (isValidDate(date))
		{
			if (std::regex_match(*value, v) && isValidValue(value))
				return (0);
		}
		return (1);
	}
	std::cout << "Error: bad input => " << line << std::endl;
	return (1);
}
