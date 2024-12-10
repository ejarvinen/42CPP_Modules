/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:36:31 by emansoor          #+#    #+#             */
/*   Updated: 2024/12/10 18:31:21 by emansoor         ###   ########.fr       */
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

class BitcoinExchange {

	private:
	
		std::map<std::string, float> _rates;

		int		initRates();
		int		validateFile(std::string fileName);
		void	processInputFile(std::string inputFile);
		int		isValidLine(std::string line, std::string *date, std::string *value);
		bool	isValidDate(std::string *date);
		bool	isValidValue(std::string *value);
		bool	checkIntValue(std::string *value);

	public:

		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &copy);
		~BitcoinExchange();
		BitcoinExchange	&operator=(BitcoinExchange const &other);
	
		void	printRates(std::string inputFile);
};

#endif