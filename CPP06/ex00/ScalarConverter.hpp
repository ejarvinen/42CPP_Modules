/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:34:13 by emansoor          #+#    #+#             */
/*   Updated: 2024/11/05 11:40:37 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H

# include <string>
# include <iostream>
# include <iomanip>
# include <ctype.h>
# include <limits>
# include <math.h>

class ScalarConverter
{
	private:

		ScalarConverter();
		ScalarConverter(ScalarConverter const &copy);
		~ScalarConverter();
		ScalarConverter	&operator=(ScalarConverter const &other);
	
		int	convertChr(int integer, char *chr);
		int	convertInt(float flt, int *integer);
		int	convertFloat(double dble, float *flt);
		int	convertDouble(std::string literal, double *dble);

		void	print(std::string chr, std::string integer, std::string flt, std::string dble);
		bool	inputChecker(std::string literal);
		bool	isValidChr(int c);
		int		handleSpecialCase(std::string literal);
		int		decimals(std::string literal);
	
	public:

		static void	convert(std::string literal, ScalarConverter &obj);
		
};

#endif