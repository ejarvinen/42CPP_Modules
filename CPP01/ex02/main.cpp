/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:02:04 by emansoor          #+#    #+#             */
/*   Updated: 2024/10/07 14:14:57 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "Memory address held by str: " << &str << std::endl;
	std::cout << "Memory address held by stringPTR: " << &*stringPTR << std::endl;
	std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << "Value of variable str: " << str << std::endl;
	std::cout << "Value of variable stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value of variable stringREF: " << stringREF << std::endl;

	return (0);
}
