/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:30:22 by emansoor          #+#    #+#             */
/*   Updated: 2024/10/23 13:51:01 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name(""), _signed(false), _signableGrade(150), _executableGrade(150)
{}

Form::Form(std::string const name, bool signedFlag, unsigned int const signableGrade, unsigned int const executableGrade) : _name(name), _signed(signedFlag), _signableGrade(signableGrade), _executableGrade(executableGrade)
{
	if (_signableGrade < 1)
		throw GradeTooHighException();
	if (_signableGrade > 150)
		throw GradeTooLowException();
	if (_executableGrade < 1)
		throw GradeTooHighException();
	if (_executableGrade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &copy)
{
	*this = copy;
}

Form::~Form() {}

