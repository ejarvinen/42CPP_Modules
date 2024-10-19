/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:50:40 by emansoor          #+#    #+#             */
/*   Updated: 2024/10/19 16:23:06 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
	
	try
	{
		ideas = new Brain;
		if (ideas)
		{}
	}
	catch(...)
	{
		std::cout << "Failed to allocate Brain for Dog" << std::endl;
	}
	this->type = "Dog";
}

Dog::Dog(std::string type) : Animal()
{
	std::cout << "Dog string constructor called" << std::endl;
	
	(void)type;
	try
	{
		ideas = new Brain;
		if (ideas)
		{}
	}
	catch(...)
	{
		std::cout << "Failed to allocate Brain for Dog" << std::endl;
	}
	this->type = "Dog";
}

Dog::Dog(const Dog &copy)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = copy;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog	&Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Woof woof!" << std::endl;
}

std::string	Dog::getType() const
{
	return (this->type);
}
