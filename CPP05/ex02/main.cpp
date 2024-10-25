/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:38:54 by emansoor          #+#    #+#             */
/*   Updated: 2024/10/25 13:38:17 by emansoor         ###   ########.fr       */
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
	
	Aurora.executeForm(pForm);
	Cinderella.executeForm(pForm);

	std::cout << std::endl;
	
	Aurora.signForm(pForm);
	Aurora.executeForm(pForm);

	std::cout << std::endl;
	
	Cinderella.executeForm(rForm);
	for (index = 28; index > 0; index--)
		Cinderella.decreaseGrade();
	Cinderella.signForm(rForm);
	Cinderella.executeForm(rForm);

	std::cout << std::endl;
	
	Aurora.signForm(sForm);
	for (index = 116; index > 0; index--)
		Aurora.decreaseGrade();
	Aurora.signForm(sForm);
	Aurora.executeForm(sForm);
	
	return (0);
}
