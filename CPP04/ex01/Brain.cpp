/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:35:00 by emansoor          #+#    #+#             */
/*   Updated: 2024/10/19 15:51:30 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	int	idea;

	std::cout << "Brain default constructor called" << std::endl;
	for (idea = 0; idea < 100; idea++)
		this->ideas[idea] = "default idea";
}

Brain::Brain(std::string idea)
{
	int	index;
	
	std::cout << "Brain string constructor called" << std::endl;
	for (index = 0; index < 100; index++)
		this->ideas[index] = idea;
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = copy;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain	&Brain::operator=(const Brain &other)
{
	int	index;
	
	if (this != &other)
	{
		for (index = 0; index < 100; index++)
			ideas[index] = other.ideas[index];
	}
	return (*this);
}
