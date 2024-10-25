/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:30:22 by emansoor          #+#    #+#             */
/*   Updated: 2024/10/25 15:59:58 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name(""), _signed(false), _signableGrade(150), _executableGrade(150)
{}

AForm::AForm(std::string const name, unsigned int const signableGrade, unsigned int const executableGrade) : _name(name), _signableGrade(signableGrade), _executableGrade(executableGrade)
{
	_signed = false;
	try
	{
		if (_signableGrade < 1 || _executableGrade < 1)
			throw GradeTooHighException();
		if (_signableGrade > 150 || _executableGrade > 150)
			throw GradeTooLowException();
	}
	catch (GradeTooHighException tooHigh)
	{
		std::cout << tooHigh.what() << std::endl;
	}
	catch (GradeTooLowException tooLow)
	{
		std::cout << tooLow.what() << std::endl;
	}
}

AForm::AForm(const AForm &copy) : _name(copy._name), _signed(copy._signed), _signableGrade(copy._signableGrade), _executableGrade(copy._executableGrade)
{
	*this = copy;
}

AForm::~AForm() {}

AForm	&AForm::operator=(AForm const &other)
{
	if (this != &other)
	{
		_signed = other._signed;
	}
	return (*this);
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::string const	&AForm::getName() const
{
	return (_name);
}

unsigned int	AForm::getSignableGrade() const
{
	return (_signableGrade);
}

unsigned int	AForm::getExecutableGrade() const
{
	return (_executableGrade);
}

bool	AForm::isSigned() const
{
	return (_signed);
}

const char	*AForm::beSigned(Bureaucrat const &bureaucrat)
{
	try
	{
		if (bureaucrat.getGrade() <= getSignableGrade())
			this->_signed = true;
		else
			throw AForm::GradeTooLowException();
	}
	catch (GradeTooLowException tooLow)
	{
		return (tooLow.what());
	}
	return ("0");
}

const char	*AForm::execute(Bureaucrat const &executor) const
{
	try
	{
		if (this->isSigned() && executor.getGrade() <= this->getExecutableGrade())
			this->action();
		else
			throw AForm::GradeTooLowException();
	}
	catch(GradeTooLowException tooLow)
	{
		return (tooLow.what());
	}
	return ("0");
}

std::ostream&	operator<<(std::ostream &out, const AForm &obj)
{
	out << "Form: " << obj.getName() << " | signable grade: " << obj.getSignableGrade() << " | executable grade: " << obj.getExecutableGrade() << " | is signed: " << obj.isSigned() << std::endl;
	return (out);
}
