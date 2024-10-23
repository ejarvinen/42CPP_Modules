/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:50:49 by emansoor          #+#    #+#             */
/*   Updated: 2024/10/23 09:21:48 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		
		std::cout << "Type for Dog: " << j->getType() << std::endl;
		std::cout << "Type for Cat: " << i->getType() << std::endl;
		
		std::cout << "What does the cat say: " << std::endl;
		i->makeSound();  //will output the cat sound!
		std::cout << "What does the dog say: " << std::endl;
		j->makeSound();
		std::cout << "What does the animal say: " << std::endl;
		meta->makeSound();

		delete(meta);
		delete(j);
		delete(i);
	}
	std::cout << std::endl;
	{
		const WrongAnimal* meta = new WrongAnimal();
		const Animal* j = new Dog();
		const WrongAnimal* i = new WrongCat();
		
		std::cout << "Type for Dog: " << j->getType() << std::endl;
		std::cout << "Type for WrongCat: " << i->getType() << std::endl;
		
		std::cout << "What does the (wrong) cat say: " << std::endl;
		i->makeSound(); // should output animal sounds
		std::cout << "What does the dog say: " << std::endl;
		j->makeSound();
		std::cout << "What does the (wrong) animal say: " << std::endl;
		meta->makeSound();

		const WrongCat test;
		const WrongAnimal test1;
		test.makeSound();
		test1.makeSound();

		delete(meta);
		delete(j);
		delete(i);
	}
	
	return 0;
}
