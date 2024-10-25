/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:38:54 by emansoor          #+#    #+#             */
/*   Updated: 2024/10/25 16:00:56 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	{
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		if (rrf)
			std::cout << *rrf;
		delete(rrf);
	}
	std::cout << std::endl;
	Intern	Yasmine;
	{
		AForm*	randomForm;
		randomForm = Yasmine.makeForm("presidential pardon", "Pinocchio");
		if (randomForm)
			std::cout << *randomForm;
		delete(randomForm);
	}
	std::cout << std::endl;
	{
		AForm*	randomForm;
		randomForm = Yasmine.makeForm("shrubbery creation", "Peter Pan");
		if (randomForm)
			std::cout << *randomForm;
		delete(randomForm);
	}
	std::cout << std::endl;
	{
		AForm*	randomForm;
		randomForm = Yasmine.makeForm("sock request", "Dobby");
		if (randomForm)
			std::cout << *randomForm;
		delete(randomForm);
	}
	return (0);
}
