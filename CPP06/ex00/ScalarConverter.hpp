/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:34:13 by emansoor          #+#    #+#             */
/*   Updated: 2024/11/09 15:04:19 by emansoor         ###   ########.fr       */
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
	
	public:

		static void	convert(std::string literal);
		
};

int	convertChr(int integer, char *chr);
int	convertInt(double dble, float flt, int *integer);
int	convertFloat(double dble, float *flt);
int	convertDouble(std::string literal, double *dble);

bool	inputChecker(std::string literal);
bool	isValidChr(int c);
int		decimals(std::string literal);

#endif