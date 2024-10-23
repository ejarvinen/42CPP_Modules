/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:50:49 by emansoor          #+#    #+#             */
/*   Updated: 2024/10/23 09:20:13 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		
		delete j;//should not create a leak
		delete i;
	}
	std::cout << std::endl;
	{
		int		index;
		Animal *pets[10];

		std::cout << "Allocating 5 Dogs:" << std::endl;
		for (index = 0; index < 5; index++)
		{
			try
			{
				pets[index] = new Dog();
			}
			catch(...)
			{
				std::cout << "Failed to allocate a Dog" << std::endl;
				for (index = 0; index < 10; index++)
					delete pets[index];
				return (1);
			}
		}
		std::cout << std::endl;
		std::cout << "Allocating 5 Cats:" << std::endl;
		for (index = 5; index < 10; index++)
		{
			try
			{
				pets[index] = new Cat();
			}
			catch(...)
			{
				std::cout << "Failed to allocate a Cat" << std::endl;
				for (index = 0; index < 10; index++)
					delete pets[index];
				return (1);
			}
		}
		std::cout << std::endl;
		std::cout << "Deleting all animals:" << std::endl;
		for (index = 0; index < 10; index++)
			delete pets[index];
		
		std::cout << std::endl;
		Dog *dog1 = new Dog();
		Dog *dog2 = new Dog(*dog1);
		dog1->printAddress();
		dog2->printAddress();
		std::cout << std::endl;
		delete(dog1);
		delete(dog2);
	}
	return 0;
}
