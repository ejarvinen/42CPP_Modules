/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:38:54 by emansoor          #+#    #+#             */
/*   Updated: 2024/10/25 15:00:37 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	Bureaucrat				Aurora("Aurora", 30);
	Bureaucrat				Cinderella("Cinderella", 45);
	ShrubberyCreationForm	sForm("shrubbery");
	RobotomyRequestForm		rForm("robotomy");
	PresidentialPardonForm	pForm("president");
	int						index;
	
	std::cout << Aurora;
	std::cout << Cinderella;	
	std::cout << pForm;
	std::cout << rForm;
	std::cout << sForm;

	std::cout << std::endl;
	
	Aurora.signForm(pForm);
	Aurora.executeForm(pForm);
	Cinderella.signForm(pForm);
	Cinderella.executeForm(pForm);
	std::cout << pForm;

	std::cout << std::endl;
	
	Aurora.signForm(rForm);
	Aurora.executeForm(rForm);
	Cinderella.executeForm(rForm);
	std::cout << rForm;

	std::cout << std::endl;
	
	Aurora.signForm(sForm);
	Aurora.executeForm(sForm);
	Cinderella.executeForm(sForm);
	std::cout << sForm;

	std::cout << std::endl;
	for (index = 25; index > 0; index--)
		Aurora.increaseGrade();
	Aurora.signForm(pForm);
	Aurora.executeForm(pForm);
	
	return (0);
}
