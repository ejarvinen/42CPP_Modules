/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:38:54 by emansoor          #+#    #+#             */
/*   Updated: 2024/10/23 13:18:59 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	Edgar;
	Bureaucrat	Fitzherbert("Fitzherbert", 57);
	Bureaucrat	Eugene(Fitzherbert);
	Bureaucrat	Barnaby("Barnaby", 1);
	
	std::cout << Edgar;
	std::cout << Fitzherbert;
	std::cout << Eugene;
	std::cout << Barnaby;

	std::cout << std::endl;

	Edgar.decreaseGrade();
	std::cout << Edgar;
	Edgar.increaseGrade();
	std::cout << Edgar;

	std::cout << std::endl;

	Fitzherbert.decreaseGrade();
	std::cout << Fitzherbert;
	Fitzherbert.increaseGrade();
	std::cout << Fitzherbert;

	std::cout << std::endl;

	Eugene.decreaseGrade();
	std::cout << Eugene;
	Eugene.increaseGrade();
	std::cout << Eugene;

	std::cout << std::endl;

	Barnaby.increaseGrade();
	std::cout << Barnaby;
	Barnaby.decreaseGrade();
	std::cout << Barnaby;

	std::cout << std::endl;

	Bureaucrat	Reginald("Reginald", -600);
	std::cout << Reginald;
	
	return (0);
}
