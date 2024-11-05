/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:38:59 by emansoor          #+#    #+#             */
/*   Updated: 2024/10/25 12:54:37 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name(""), _grade(150)
{}

Bureaucrat::Bureaucrat(std::string const name, unsigned int grade) : _name(name)
{
	try
	{
		_grade = grade;
		if (_grade < 1)
			throw GradeTooHighException();
		if (_grade > 150)
			throw GradeTooLowException();
	}
	catch (GradeTooHighException tooHigh)
	{
		std::cout << tooHigh.what() << std::endl;
		_grade = 1;
	}
	catch (GradeTooLowException tooLow)
	{
		std::cout << tooLow.what() << std::endl;
		_grade = 150;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	*this = copy;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &other)
{
	if (this != &other)
	{
		_grade = other._grade;
	}
	return (*this);
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

std::string const	&Bureaucrat::getName() const
{
	return (_name);
}

unsigned int	Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::increaseGrade()
{
	try
	{
		_grade = _grade - 1;
		if (_grade < 1)
			throw GradeTooHighException();
	}
	catch (GradeTooHighException tooHigh)
	{
		std::cout << tooHigh.what() << std::endl;
		_grade = 1;
	}
}

void	Bureaucrat::decreaseGrade()
{
	try
	{
		_grade = _grade + 1;
		if (_grade > 150)
			throw GradeTooLowException();
	}
	catch (GradeTooLowException tooLow)
	{
		std::cout << tooLow.what() << std::endl;
		_grade = 150;
	}
}

void	Bureaucrat::signForm(AForm &form)
{
	std::string	reason;
	
	reason = form.beSigned(*this);
	if (form.isSigned())
		std::cout << _name << " signed " << form.getName() << std::endl;
	else
		std::cout << _name << " couldn't sign " << form.getName() << " because " << reason << std::endl;
}

void	Bureaucrat::executeForm(AForm const &form)
{
	std::string	reason;

	reason = form.execute(*this);
	if (reason.compare("0") == 0)
		std::cout << _name << " executed " << form.getName() << std::endl;
	else
		std::cout << _name << " tried to execute " << form.getName() << ", but failed due to " << reason << std::endl;
}

std::ostream&	operator<<(std::ostream &out, const Bureaucrat &obj)
{
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << std::endl;
	return (out);
}