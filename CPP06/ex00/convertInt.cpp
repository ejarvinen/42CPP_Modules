/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertInt.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 12:50:24 by emansoor          #+#    #+#             */
/*   Updated: 2024/11/03 12:50:25 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

std::string	ScalarConverter::convertInt(std::string literal)
{
	int			nbr;
	std::string	res;

	try
	{
		nbr = stoi(literal);
	}
	catch (...)
	{
		return ("impossible");
	}
	res = std::to_string(nbr);
	return (res);
}
