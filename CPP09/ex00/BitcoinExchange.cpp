/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:12:18 by emansoor          #+#    #+#             */
/*   Updated: 2024/12/09 15:05:36 by emansoor         ###   ########.fr       */
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
	if (std::filesystem::is_directory(fileName) || inFile.peek() == std::ifstream::traits_type::eof())
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
		_rates[line.substr(0, sep)] = std::stof(line.substr(sep + 1, std::string::npos));
		//_rates.insert(pair<std::string, float>(line.substr(0, sep), std::stof(line.substr(sep + 1, std::string::npos))));
	}
	dataBase.close();
	return (0);
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
}
