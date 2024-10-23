/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:38:57 by emansoor          #+#    #+#             */
/*   Updated: 2024/10/23 12:54:27 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat : public std::exception {

	private:

		std::string const 	_name;
		unsigned int		_grade;

	public:

		Bureaucrat();
		Bureaucrat(std::string const name, unsigned int grade);
		Bureaucrat(const Bureaucrat &copy);
		~Bureaucrat();
		Bureaucrat &operator=(Bureaucrat const &other);

		std::string const 	&getName() const;
		unsigned int		getGrade() const;
		void				increaseGrade();
		void				decreaseGrade();

		class GradeTooHighException : public std::exception {
			
			public:

				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			
			public:

				const char *what() const throw();
		};
		
};

std::ostream&	operator<<(std::ostream &out, const Bureaucrat &obj);

#endif