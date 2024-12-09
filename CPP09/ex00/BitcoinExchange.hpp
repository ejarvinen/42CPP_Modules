/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:36:31 by emansoor          #+#    #+#             */
/*   Updated: 2024/12/09 14:59:17 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_H
# define BITCOINEXCHANGE_H

# include <iostream>
# include <string>
# include <map>
# include <fstream>
# include <filesystem>

class BitcoinExchange {

	private:
	
		std::map<std::string, float> _rates;

		int	initRates();
		int	validateFile(std::string fileName);

	public:

		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &copy);
		~BitcoinExchange();
		BitcoinExchange	&operator=(BitcoinExchange const &other);
	
		void	printRates(std::string inputFile);
};

#endif