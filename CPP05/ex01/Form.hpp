/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:20:53 by emansoor          #+#    #+#             */
/*   Updated: 2024/10/24 12:11:44 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form : std::exception {

	private:

		std::string const	_name;
		bool				_signed;
		unsigned int const	_signableGrade;
		unsigned int const	_executableGrade;

	public:

		Form();
		Form(std::string const name, unsigned int const signableGrade, unsigned int const executableGrade);
		Form(const Form &copy);
		~Form();
		Form &operator=(Form const &other);

		class GradeTooHighException : public std::exception {
			
			public:

				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			
			public:

				const char *what() const throw();
		};

		std::string const 	&getName() const;
		unsigned int		getSignableGrade() const;
		unsigned int		getExecutableGrade() const;
		bool				isSigned() const;
		const char			*beSigned(Bureaucrat const &bureaucrat);
		
};

std::ostream&	operator<<(std::ostream &out, const Form &obj);

#endif