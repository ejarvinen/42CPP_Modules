/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:36:31 by emansoor          #+#    #+#             */
/*   Updated: 2024/12/11 14:59:11 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_H
# define BITCOINEXCHANGE_H

# include <iostream>
# include <string>
# include <map>
# include <fstream>
# include <filesystem>
# include <regex>
# include <ctime>

class BitcoinExchange {

	private:
	
		std::map<std::string, float> _rates;

		int			initRates();
		int			validateFile(std::string fileName);
		void		processInputFile(std::string inputFile);
		int			isValidLine(std::string line, std::string *date, std::string *value);
		bool		isValidDate(std::string *date);
		bool		isValidValue(std::string *value);
		bool		checkIntValue(std::string *value);
		void		findRate(std::string date, std::string value);
		void		findPrevRate(std::string date, std::string value, float val);
		std::string	getYesterday(std::string dt);
		bool		isLeapYear(std::string date);
		bool		isFuture(std::string *date);

	public:

		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &copy);
		~BitcoinExchange();
		BitcoinExchange	&operator=(BitcoinExchange const &other);
	
		void	printRates(std::string inputFile);
};

#endif