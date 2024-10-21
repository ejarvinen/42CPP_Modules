/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:50:34 by emansoor          #+#    #+#             */
/*   Updated: 2024/10/21 12:34:21 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat default constructor called" << std::endl;

	try
	{
		ideas = new Brain;
	}
	catch(...)
	{
		std::cout << "Failed to allocate Brain for Cat" << std::endl;
	}
	this->type = "Cat";
}

Cat::Cat(std::string type) : Animal()
{
	std::cout << "Cat string constructor called" << std::endl;
	
	(void)type;
	try
	{
		ideas = new Brain;
	}
	catch(...)
	{
		std::cout << "Failed to allocate Brain for Cat" << std::endl;
	}
	this->type = "Cat";
}

Cat::Cat(const Cat &copy)
{
	std::cout << "Cat copy constructor called" << std::endl;
	try
	{
		ideas = new Brain;
		if (ideas)
		{
			*ideas = *(copy.ideas);
		}
	}
	catch(...)
	{
		std::cout << "Failed to allocate a Brain copy for Cat" << std::endl;
	}
	type = copy.type;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete(ideas);
}

Cat	&Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		type = other.type;
		*ideas = *(other.ideas);
	}
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}
