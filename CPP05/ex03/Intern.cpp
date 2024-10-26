/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:25:03 by emansoor          #+#    #+#             */
/*   Updated: 2024/10/26 12:32:19 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &copy)
{
	*this = copy;
}

Intern::~Intern() {}

Intern	&Intern::operator=(Intern const &other)
{
	if (this != &other)
	{}
	return (*this);
}

const char	*Intern::IncorrectForm::what() const throw()
{
	return ("Incorrect form type");
}

AForm	*Intern::createForm(std::string formType, std::string formTarget)
{
	int			form;
	std::string	types[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	
	for (form = 0; form < 3; form++)
	{
		if (types[form].compare(formType) == 0)
			break ;
	}
	switch (form) {
				
		case 0:
		{
			std::cout << "Intern creates " << formType << std::endl;
			return (new ShrubberyCreationForm(formTarget));
		}
		case 1:
		{
			std::cout << "Intern creates " << formType << std::endl;
			return (new RobotomyRequestForm(formTarget));
		}
		case 2:
		{
			std::cout << "Intern creates " << formType << std::endl;
			return (new PresidentialPardonForm(formTarget));
		}
		case 3:
		{}
	}
	return (nullptr);
}

AForm	*Intern::makeForm(std::string formType, std::string formTarget)
{
	AForm	*form = nullptr;

	try
	{
		form = createForm(formType, formTarget);
		if (form)
		{
			return (form);
		}
		else
			throw IncorrectForm();
	}
	catch (IncorrectForm form)
	{
		std::cout << form.what() << std::endl;
	}
	return (form);
}

/* int	Intern::isValid(std::string formType)
{
	int			form;
	std::string	types[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	
	for (form = 0; form < 3; form++)
	{
		if (types[form].compare(formType) == 0)
			return (form);
	}
	return (-1);
}

AForm	*Intern::makeForm(std::string formType, std::string formTarget)
{
	int	form;
	
	try
	{
		form = isValid(formType);
		if (form > -1)
		{
			switch (form) {
				
				case 0:
				{
					std::cout << "Intern creates " << formType << std::endl;
					return (new ShrubberyCreationForm(formTarget));
				}
				case 1:
				{
					std::cout << "Intern creates " << formType << std::endl;
					return (new RobotomyRequestForm(formTarget));
				}
				case 2:
				{
					std::cout << "Intern creates " << formType << std::endl;
					return (new PresidentialPardonForm(formTarget));
				}
			}
		}
		else
			throw IncorrectForm();
	}
	catch (IncorrectForm form)
	{
		std::cout << form.what() << std::endl;
	}
	return (nullptr);
} */
