/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:20:53 by emansoor          #+#    #+#             */
/*   Updated: 2024/10/28 07:10:50 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm : std::exception {

	private:

		std::string const	_name;
		bool				_signed;
		unsigned int const	_signableGrade;
		unsigned int const	_executableGrade;

	public:

		AForm();
		AForm(std::string const name, unsigned int const signableGrade, unsigned int const executableGrade);
		AForm(const AForm &copy);
		virtual ~AForm();
		AForm &operator=(AForm const &other);

		class GradeTooHighException : public std::exception {
			
			public:

				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			
			public:

				const char *what() const throw();
		};

		class NotSignedException : public std::exception {
			
			public:

				const char *what() const throw();
		};

		std::string const 	&getName() const;
		unsigned int		getSignableGrade() const;
		unsigned int		getExecutableGrade() const;
		bool				isSigned() const;
		const char			*beSigned(Bureaucrat const &bureaucrat);
		virtual void		action() const = 0;
		const char			*execute(Bureaucrat const &executor) const;
		
};

std::ostream&	operator<<(std::ostream &out, const AForm &obj);

#endif