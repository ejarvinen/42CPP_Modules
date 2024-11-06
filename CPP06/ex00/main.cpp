/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:40:25 by emansoor          #+#    #+#             */
/*   Updated: 2024/11/06 11:56:23 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Please give one argument to convert" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}
