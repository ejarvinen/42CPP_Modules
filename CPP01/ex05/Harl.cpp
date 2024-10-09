/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:21:41 by emansoor          #+#    #+#             */
/*   Updated: 2024/10/09 16:03:19 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){}

Harl::~Harl(){}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

Harl::Level	Harl::convertLevel(std::string level)
{
	if (level.compare("DEBUG") == 0)
		return (DEBUG);
	if (level.compare("INFO") == 0)
		return (INFO);
	if (level.compare("WARNING") == 0)
		return (WARNING);
	if (level.compare("ERROR") == 0)
		return (ERROR);
	return (FAIL);
}

void	Harl::complain(std::string level)
{
	enum	Level newVar = convertLevel(level);
	
	switch (newVar)
	{
		case 0:
		{
			return (this->debug());
		}
		case 1:
		{
			return (this->info());
		}
		case 2:
		{
			return (this->warning());
		}
		case 3:
		{
			return (this->error());
		}
		default :
			std::cout << "Invalid complaint" << std::endl;
	}
}
