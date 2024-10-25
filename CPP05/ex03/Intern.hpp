/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:06:14 by emansoor          #+#    #+#             */
/*   Updated: 2024/10/25 15:56:19 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
# define INTERN_H

# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern : public std::exception {

	private:

		int	isValid(std::string formType);

	public:

		Intern();
		Intern(const Intern &copy);
		~Intern();
		Intern	&operator=(Intern const &other);

		AForm	*makeForm(std::string formType, std::string formTarget);

		class IncorrectForm : public std::exception {
			
			public:

				const char *what() const throw();
		};

};

#endif