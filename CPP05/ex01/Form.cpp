/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:30:22 by emansoor          #+#    #+#             */
/*   Updated: 2024/10/24 12:16:59 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name(""), _signed(false), _signableGrade(150), _executableGrade(150)
{}

Form::Form(std::string const name, unsigned int const signableGrade, unsigned int const executableGrade) : _name(name), _signableGrade(signableGrade), _executableGrade(executableGrade)
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

Form::Form(const Form &copy) : _name(copy._name), _signed(copy._signed), _signableGrade(copy._signableGrade), _executableGrade(copy._executableGrade)
{
	*this = copy;
}

Form::~Form() {}

Form	&Form::operator=(Form const &other)
{
	if (this != &other)
	{
		_signed = other._signed;
	}
	return (*this);
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::string const	&Form::getName() const
{
	return (_name);
}

unsigned int	Form::getSignableGrade() const
{
	return (_signableGrade);
}

unsigned int	Form::getExecutableGrade() const
{
	return (_executableGrade);
}

bool	Form::isSigned() const
{
	return (_signed);
}

const char	*Form::beSigned(Bureaucrat const &bureaucrat)
{
	try
	{
		if (bureaucrat.getGrade() >= getSignableGrade())
			this->_signed = true;
		else
			throw Form::GradeTooLowException();
	}
	catch (GradeTooLowException tooLow)
	{
		return (tooLow.what());
	}
	return ("0");
}

std::ostream&	operator<<(std::ostream &out, const Form &obj)
{
	out << "Form: " << obj.getName() << " | signable grade: " << obj.getSignableGrade() << " | executable grade: " << obj.getExecutableGrade() << " | is signed: " << obj.isSigned() << std::endl;
	return (out);
}
