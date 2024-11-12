/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helperFunctions.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:54:30 by emansoor          #+#    #+#             */
/*   Updated: 2024/11/12 12:33:23 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool	isValidChr(int c)
{
	return (std::isdigit(c) || c == '.' || c == 'f' || c == '-' || c == '+');
}

bool	inputChecker(std::string literal)
{
	int	index;
	int	points = 0;

	if (!literal.compare("nan") || !literal.compare("nanf")
		|| !literal.compare("+inf") || !literal.compare("+inff")
		|| !literal.compare("-inf") || !literal.compare("-inff"))
		return (true);
	for (index = 0; literal[index]; index++)
	{
		if (isValidChr(literal[index]))
		{
			if (literal[index] == '.')
				points++;
			if ((literal[index] == 'f' && literal[index + 1])
				|| (literal[index] == 'f' && index > 0 && literal[index - 1] == '.')
				|| (literal[index] == '+' && index > 0)
				|| (literal[index] == '-' && index > 0)
				|| points > 1)
					return (false);
		}
		else
			return (false);
	}
	return (true);
}

int	decimals(std::string literal)
{
	size_t	pointIndex;
	size_t	index;
	int		decims;

	decims = 1;
	pointIndex = literal.find(".");
	if (pointIndex != std::string::npos)
	{
		decims = 0;
		for (index = pointIndex + 1; std::isdigit(literal[index]) != 0; index++)
		{
			decims++;
		}
	}
	return (decims);
}
