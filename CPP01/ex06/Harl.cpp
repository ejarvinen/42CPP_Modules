/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 08:51:00 by emansoor          #+#    #+#             */
/*   Updated: 2024/10/12 09:04:47 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){}

Harl::~Harl(){}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\nI really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money.\nYou didn't put enough bacon in my burger!\nIf you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free.\nI've been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
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
	int		index;
	enum	Level levelIndex = convertLevel(level);
	void	(Harl::*functionPtr[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	
	index = levelIndex;
	switch (levelIndex)
	{
		case 0:
		{
			std::cout << "[ DEBUG ]" << std::endl;
			(this->*functionPtr[index++])();
			std::cout << std::endl;
		}
		case 1:
		{
			std::cout << "[ INFO ]" << std::endl;
			(this->*functionPtr[index++])();
			std::cout << std::endl;
		}
		case 2:
		{
			std::cout << "[ WARNING ]" << std::endl;
			(this->*functionPtr[index++])();
			std::cout << std::endl;
		}
		case 3:
		{
			std::cout << "[ ERROR ]" << std::endl;
			(this->*functionPtr[index++])();
			std::cout << std::endl;
			break ;
		}
		default :
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
