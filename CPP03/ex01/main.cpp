/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:50:12 by emansoor          #+#    #+#             */
/*   Updated: 2024/10/18 11:11:05 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	Herbert;
	ScavTrap	Isaac("Isaac");
	ScavTrap	FakeIsaac(Isaac);
	int			punch;

	std::cout << "Mr. Herbert (who doesn't have a name) attacks poor Mr. Isaac:" << std::endl;
	Herbert.attack("Isaac");
	Isaac.takeDamage(5);
	
	std::cout << std::endl;
	std::cout << "Mr. Isaac's evil cousin attacks Mr. Herbert, however, Mr. Herbert suffers no damages:" << std::endl;
	FakeIsaac.attack("Herbert");
	Herbert.takeDamage(0);
	
	std::cout << std::endl;
	std::cout << "Mr. Herbert goes livid due to this atrocity and decides to show Mr. Isaac's evil cousin who's da boss:" << std::endl;
	for (punch = 0; punch < 11; punch++)
		Herbert.attack("FakeIsaac");

	std::cout << std::endl;
	FakeIsaac.guardGate();
	std::cout << "Mr. Herbert (who still doesn't know his name) drinks Kool-Aid to calm down:" << std::endl;
	Herbert.beRepaired(10);
	
	return (0);
}
