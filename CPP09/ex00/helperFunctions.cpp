/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helperFunctions.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:00:47 by emansoor          #+#    #+#             */
/*   Updated: 2024/12/11 15:49:35 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

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

bool	BitcoinExchange::isLeapYear(std::string date)
{
	int	y;

	y = std::stoi(date);
	if (y % 100 == 0 && y % 400 == 0)
		return (true);
	return (false);
}

bool	BitcoinExchange::isFuture(std::string *date)
{
	time_t		rawTime;
	struct tm	*timeInfo;
	char		timeStamp[11];
	std::string	tstamp;
	
	time(&rawTime);
	timeInfo = localtime(&rawTime);
	
	if (strftime(timeStamp, 11, "%F", timeInfo) != 0)
	{
		tstamp = timeStamp;
		if (tstamp.compare(*date) >= 0)
			return (false);
	}
	return (true);
}
