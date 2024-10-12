/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 08:50:22 by emansoor          #+#    #+#             */
/*   Updated: 2024/10/12 08:50:27 by emansoor         ###   ########.fr       */
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
