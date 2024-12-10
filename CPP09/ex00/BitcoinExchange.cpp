/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:12:18 by emansoor          #+#    #+#             */
/*   Updated: 2024/12/10 18:47:47 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy) : _rates(copy._rates)
{}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &other)
{
	if (this != &other)
	{
		_rates = other._rates;
	}
	return (*this);
}

int	BitcoinExchange::validateFile(std::string fileName)
{
	std::ifstream	inFile(fileName);

	if (!inFile.is_open())
		return (1);
	if (std::filesystem::is_directory(fileName)
		|| inFile.peek() == std::ifstream::traits_type::eof())
	{
		inFile.close();
		return (1);
	}
	inFile.close();
	return (0);
}

int	BitcoinExchange::initRates()
{
	std::string		line;
	std::size_t		sep;
	std::ifstream	dataBase("data.csv");
	
	while (getline(dataBase, line))
	{
		sep = line.find(',');
		if (sep == std::string::npos)
		{
			dataBase.close();
			return (1);
		}
		try
		{
			_rates[line.substr(0, sep)] = std::stof(line.substr(sep + 1, std::string::npos));
		}
		catch (const std::exception& e)
		{
			_rates[line.substr(0, sep)] = -0;
		}
	}
	dataBase.close();
	return (0);
}

bool	BitcoinExchange::isValidDate(std::string *date)
{
	int	y;
	int	m;
	int	d;

	y = std::stoi(*date);
	if (y < 2009 || y > 2024)
	{
		std::cout << "Error: invalid year" << std::endl;
		return (false);
	}
	m = std::stoi((*date).substr(5, 7));
	if (m < 1 || m > 12)
	{
		std::cout << "Error: invalid month" << std::endl;
		return (false);
	}
	d = std::stoi((*date).substr(8, std::string::npos));
	if (d < 1 || d > 31)
	{
		std::cout << "Error: invalid date" << std::endl;
		return (false);
	}
	if ((d == 31 && (m == 2 || m == 4 || m == 6 || m == 9 || m == 11))
		|| (m == 2 && d == 29 && !(y == 2012 || y == 2016 || y == 2020 || y == 2024))
		|| (m == 2 && d == 30))
	{
		std::cout << "Error: date doesn't exist" << std::endl;
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
			std::cout << "Error: not a positive number" << std::endl;
		else
			std::cout << "Error: too large a number" << std::endl;
		return (false);
	}
	if (val > 1000)
	{
		std::cout << "Error: too large a number" << std::endl;
		return (false);
	}
	else if (val < 0)
	{
		std::cout << "Error: not a positive number" << std::endl;
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
				std::cout << "Error: not a positive number" << std::endl;
			else
				std::cout << "Error: too large a number" << std::endl;
			return (false);
		}
		if (val > 1000.0)
		{
			std::cout << "Error: too large a number" << std::endl;
			return (false);
		}
		else if (val < 0.0)
		{
			std::cout << "Error: not a positive number" << std::endl;
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

void	BitcoinExchange::processInputFile(std::string inputFile)
{
	std::ifstream	inFile(inputFile);
	std::string		line;
	int				lineCount;
	std::string		date;
	std::string		value;
	
	if (!inFile.is_open())
		return ;
	lineCount = 0;
	while (getline(inFile, line))
	{
		if (lineCount > 0)
		{
			if (isValidLine(line, &date, &value) == 0)
			{
				
			}
			// 	findRate(date, value);
		}
		lineCount++;
	}
	// find matching date from database, if found print to stdout
	// else use later date, print to stdout -> print error if later date doesnt exist
	// else print appropriate error message
}

void	BitcoinExchange::printRates(std::string inputFile)
{
	if (validateFile("data.csv") || initRates())
	{
		std::cout << "Error: faulty database file" << std::endl;
		return ;
	}
	if (validateFile(inputFile))
	{
		std::cout << "Error: faulty input file" << std::endl;
		return ;
	}
	processInputFile(inputFile);
}
