/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:34:13 by emansoor          #+#    #+#             */
/*   Updated: 2024/11/03 12:39:05 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H

# include <string>
# include <iostream>
# include <iomanip> // remove before submitting
# include <ctype.h>

class ScalarConverter
{
	private:

		ScalarConverter();
		ScalarConverter(ScalarConverter const &copy);
		~ScalarConverter();
		ScalarConverter	&operator=(ScalarConverter const &other);
	
		std::string	convertChr(std::string const literal);
		std::string	convertInt(std::string literal);
		std::string	convertFloat(std::string literal);
		std::string	convertDouble(std::string literal);

		std::string	floatDecimalHandler(std::string literal, std::string res, size_t pointIndex);
		std::string	doubleDecimalHandler(std::string literal, std::string res, size_t pointIndex);
		std::string	rounder(std::string res, size_t pointIndex, int decim);
	
	public:

		static void	convert(std::string literal, ScalarConverter &obj);
		
};

#endif