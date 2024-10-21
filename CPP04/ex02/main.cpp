/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:50:49 by emansoor          #+#    #+#             */
/*   Updated: 2024/10/21 14:33:36 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	//const Animal* meta = new Animal(); // comment in to test for abstraction
	const Animal*	j = new Dog();
	const Animal*	i = new Cat();
	//const Animal hello();
	
	std::cout << "Type for Dog is: " << j->getType() << std::endl;
	std::cout << "Type for Cat is: " << i->getType() << std::endl;
	std::cout << "What does the cat say:" << std::endl;
	i->makeSound(); //will output the cat sound!
	std::cout << "What does the dog say:" << std::endl;
	j->makeSound();
	//meta->makeSound();

	delete(j);
	delete(i);
	
	return 0;
}
