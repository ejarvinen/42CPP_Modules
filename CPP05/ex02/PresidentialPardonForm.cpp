/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:18:00 by emansoor          #+#    #+#             */
/*   Updated: 2024/10/31 12:38:24 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
{
	_target = "default target";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5)
{
	_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
{
	*this = copy;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
	if (this != &other)
	{
		_target = other._target;
	}
	return (*this);
}

const char	*PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	try
	{
		if (!this->isSigned())
			throw AForm::NotSignedException();
		else if (executor.getGrade() <= this->getExecutableGrade())
		{
			std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
		}
		else
			throw AForm::GradeTooLowException();
	}
	catch (NotSignedException notSigned)
	{
		return (notSigned.what());
	}
	catch(GradeTooLowException tooLow)
	{
		return (tooLow.what());
	}
	return ("0");
}
