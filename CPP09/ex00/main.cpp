/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:24:54 by emansoor          #+#    #+#             */
/*   Updated: 2024/12/09 12:39:42 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cout << "Error: could not open file" << std::endl;
		return (1);
	}
	else if (argc > 2)
	{
		std::cout << "Error: too many arguments, please specify one file" << std::endl;
		return (1);
	}
	BitcoinExchange btc;
	btc.printRates(argv[1]);
	return (0);
}
