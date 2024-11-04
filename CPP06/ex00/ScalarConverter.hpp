/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:34:13 by emansoor          #+#    #+#             */
/*   Updated: 2024/11/04 15:59:15 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H

# include <string>
# include <iostream>
# include <iomanip> // remove before submitting
# include <ctype.h>
# include <limits>

class ScalarConverter
{
	private:

		ScalarConverter();
		ScalarConverter(ScalarConverter const &copy);
		~ScalarConverter();
		ScalarConverter	&operator=(ScalarConverter const &other);
	
		//std::string	convertChr(std::string const literal);
		int	convertChr(std::string const literal);
		//std::string	convertInt(std::string literal);
		int	convertInt(float flt, int *integer);
		//std::string	convertFloat(std::string literal);
		int	convertFloat(double dble, float *flt);
		//std::string	convertDouble(std::string literal);
		int	convertDouble(std::string literal, double *dble);

		std::string	floatDecimalHandler(std::string literal, std::string res, size_t pointIndex);
		std::string	doubleDecimalHandler(std::string literal, std::string res, size_t pointIndex);
		std::string	rounder(std::string res, size_t pointIndex, int decim);
		void		print(std::string chr, std::string integer, std::string flt, std::string dble);
		bool		inputChecker(std::string literal);
		bool		isValidChr(int c);
		int			handleSpecialCase(std::string literal);
	
	public:

		static void	convert(std::string literal, ScalarConverter &obj);
		
};

#endif