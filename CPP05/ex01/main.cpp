/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:38:54 by emansoor          #+#    #+#             */
/*   Updated: 2024/10/25 14:47:56 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	Bureaucrat	Aurora("Aurora", 30);
	Bureaucrat	Cinderella("Cinderella", 45);
	Form		BirthAffidavit("Birth Affidavit", 35, 1);
	Form		SeparationStatement("Separation Statement", 13, 1);
	Form		MarriageLicense("Marriage License", 125, 1);

	std::cout << BirthAffidavit;
	std::cout << SeparationStatement;
	std::cout << MarriageLicense;

	BirthAffidavit.isSigned();
	SeparationStatement.isSigned();
	MarriageLicense.isSigned();

	std::cout << std::endl;

	Aurora.signForm(MarriageLicense);
	std::cout << MarriageLicense;

	std::cout << std::endl;

	Cinderella.signForm(BirthAffidavit);
	std::cout << BirthAffidavit;
	Aurora.signForm(BirthAffidavit);
	std::cout << BirthAffidavit;

	std::cout << std::endl;

	Cinderella.signForm(SeparationStatement);
	std::cout << SeparationStatement;
	Aurora.signForm(SeparationStatement);
	std::cout << SeparationStatement;
	
	return (0);
}
