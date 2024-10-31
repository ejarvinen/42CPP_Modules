/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:39:52 by emansoor          #+#    #+#             */
/*   Updated: 2024/10/31 12:34:39 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{	
	_target = "default target";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{
	_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
{
	*this = copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	if (this != &other)
	{
		_target = other._target;
	}
	return (*this);
}

void	ShrubberyCreationForm::plantTrees(std::ofstream &outFile) const
{
	outFile << "               ,@@@@@@@,\n";
	outFile << "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n";
	outFile << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n";
	outFile << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n";
	outFile << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n";
	outFile << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n";
	outFile << "   `&%\\ ` /%&'    |.|        \\ '|8'\n";
	outFile << "       |o|        | |         | |\n";
	outFile << "       |.|        | |         | |\n";
	outFile << "    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_\n";
	outFile << std::endl;
}

void	ShrubberyCreationForm::shrubbery() const
{
	int				trees;
	int				index;
	std::ofstream	outFile(_target + "_shrubbery");
	
	if (!outFile.is_open())
	{
		std::cout << "Error opening file for shrubbery" << std::endl;
	}
	else
	{
		trees = std::rand() % 50 + 1;
		for (index = 0; index < trees; index++)
			this->plantTrees(outFile);
		outFile.close();
	}
}

const char	*ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	try
	{
		if (!this->isSigned())
			throw AForm::NotSignedException();
		else if (executor.getGrade() <= this->getExecutableGrade())
			this->shrubbery();
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
