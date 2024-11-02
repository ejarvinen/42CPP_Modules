/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:40:25 by emansoor          #+#    #+#             */
/*   Updated: 2024/11/01 13:18:13 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char *argv[])
{
	ScalarConverter	*dummy = nullptr;
	
	if (argc != 2)
	{
		std::cout << "Please give one argument to convert" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1], *dummy);
	return (0);
}
