/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:12:18 by emansoor          #+#    #+#             */
/*   Updated: 2024/12/11 16:13:13 by emansoor         ###   ########.fr       */
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
			_rates[line.substr(0, sep)] = -1;
		}
	}
	dataBase.close();
	return (0);
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
				findRate(date, value);
			}
		}
		lineCount++;
	}
	inFile.close();
}

void	BitcoinExchange::printRates(std::string inputFile)
{
	if (validateFile("data.csv") || initRates())
	{
		std::cout << "Error: faulty database file." << std::endl;
		return ;
	}
	if (validateFile(inputFile))
	{
		std::cout << "Error: faulty input file." << std::endl;
		return ;
	}
	processInputFile(inputFile);
}
