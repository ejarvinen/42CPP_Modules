/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:38:54 by emansoor          #+#    #+#             */
/*   Updated: 2024/10/28 07:31:06 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
