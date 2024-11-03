/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertChr.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 12:50:27 by emansoor          #+#    #+#             */
/*   Updated: 2024/11/03 12:50:28 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

std::string	ScalarConverter::convertChr(std::string const literal)
{
	int			chr;
	char		ch;
	std::string	res = "'";

	try
	{
		chr = stoi(literal);
		if (chr < 32 || chr > 126)
		{
			if (chr > 126 || chr < 0)
				return ("impossible");
			return ("Non displayable");
		}
	}
	catch (...)
	{
		if (literal.length() == 1)
		{
			res = res + literal;
			res.append("'");
			return (res);
		}
		return ("impossible");
	}
	try
	{
		ch = static_cast<char>(chr);
	}
	catch (...)
	{
		return ("Static cast failed");
	}
	res = res + ch;
	res.append("'");
	return (res);
}
