/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:02:16 by emansoor          #+#    #+#             */
/*   Updated: 2024/10/31 12:36:23 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
	_target = "default target";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
	_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
{
	*this = copy;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
	if (this != &other)
	{
		_target = other._target;
	}
	return (*this);
}

void	RobotomyRequestForm::robotomy() const
{
	int	successRate;

	std::cout << "** LOUD DRILLING NOISES **" << std::endl;
	successRate = rand() % 100;
	if (successRate % 2 == 0)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "Robotomizing " << _target << " failed horribly" << std::endl;
}

const char	*RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	try
	{
		if (!this->isSigned())
			throw AForm::NotSignedException();
		else if (executor.getGrade() <= this->getExecutableGrade())
			this->robotomy();
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