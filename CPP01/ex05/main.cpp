/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:21:44 by emansoor          #+#    #+#             */
/*   Updated: 2024/10/09 12:46:39 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char *argv[])
{
	Harl		Harl;
	std::string	level;

	if (argc != 2)
	{
		std::cout << "Invalid arguments" << std::endl;
		return (1);
	}
	level = argv[1];
	Harl.complain(level);
	return (0);
}
