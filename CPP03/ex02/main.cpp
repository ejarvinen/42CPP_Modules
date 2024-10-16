/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:50:12 by emansoor          #+#    #+#             */
/*   Updated: 2024/10/16 15:52:25 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void)
{
	FragTrap	Jackson;
	FragTrap	Kirk("Kirk");
	FragTrap	FakeKirk(Kirk);
	int			punch;

	std::cout << "Mr. Jackson (who doesn't have a name) attacks poor Mr. Kirk:" << std::endl;
	Jackson.attack("Kirk");
	Kirk.takeDamage(100);
	
	std::cout << std::endl;
	std::cout << "Mr. Kirk's evil cousin attacks Mr. Jackson, however, Mr. Jackson suffers no damages:" << std::endl;
	FakeKirk.attack("Jackson");
	Jackson.takeDamage(0);
	
	std::cout << std::endl;
	std::cout << "Mr. Jackson goes livid due to this atrocity and decides to show Mr. Kirk's evil cousin who's da boss:" << std::endl;
	for (punch = 0; punch < 10; punch++)
		Jackson.attack("FakeKirk");

	std::cout << std::endl;
	Kirk.highFivesGuys();
	std::cout << "Mr. Jackson (who still doesn't know his name) drinks Kool-Aid to calm down:" << std::endl;
	Jackson.beRepaired(10);
	
	return (0);
}
