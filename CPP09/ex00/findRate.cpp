/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findRate.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:08:40 by emansoor          #+#    #+#             */
/*   Updated: 2024/12/11 14:25:15 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::string	BitcoinExchange::getYesterday(std::string dt)
{
	int			y;
	int			m;
	int			d;
	std::string	yesterday;

	y = std::stoi(dt);
	m = std::stoi(dt.substr(5, 7));
	d = std::stoi(dt.substr(8, std::string::npos));
	if (d == 1)
	{
		d = 31;
		if (m == 1)
		{
			y--;
			m = 12;
		}
		else
		{
			m--;
			if ((m < 7 && m % 2 == 0) || (m < 8 && m % 2 != 0))
			{
				if (m == 2 && isLeapYear(dt))
					d = 29;
				else if (m == 2 && !isLeapYear(dt))
					d = 28;
				else
					d = 30;
			}
		}
	}
	else
		d--;
	yesterday = std::to_string(y) + "-";
	if (m < 10)
		yesterday.append("0");
	yesterday = yesterday + std::to_string(m) + "-";
	if (d < 10)
		yesterday.append("0");
	yesterday.append(std::to_string(d));
	return (yesterday);
}

void	BitcoinExchange::findPrevRate(std::string date, std::string value, float val)
{
	std::string	dt = date;
	std::map<std::string, float>::iterator it = _rates.find(dt);
	
	while (it == _rates.end())
	{
		dt = getYesterday(dt);
		it = _rates.find(dt);
	}
	std::cout << date << " => " << value << " = " << it->second * val << std::endl;
}

void	BitcoinExchange::findRate(std::string date, std::string value)
{
	float	val;
	std::map<std::string, float>::iterator it = _rates.begin();
	
	val = std::stof(value);
	while (it != _rates.end())
	{
		if (it->first.compare(date) == 0)
		{
			std::cout << date << " => " << value << " = " << it->second * val << std::endl;
			return ;
		}
		it++;
	}
	findPrevRate(date, value, val);
}
