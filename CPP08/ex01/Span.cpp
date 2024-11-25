/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:26:04 by emansoor          #+#    #+#             */
/*   Updated: 2024/11/25 15:50:48 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _N(0)
{}

Span::Span(unsigned int N) : _N(N)
{}

Span::Span(Span const &copy) : _nums(copy._nums), _N(copy._N)
{}

Span::~Span()
{}

Span	&Span::operator=(Span const &other)
{
	if (this != &other)
	{
		_N = other._N;
		_nums.assign(other._nums.begin(), other._nums.end());
	}
	return (*this);
}

void	Span::addNumber(int newNbr)
{
	if (_N != 0 && (unsigned int)_nums.size() < _N)
	{
		_nums.push_back(newNbr);
		return ;
	}
	throw std::out_of_range("There's no space for a new number to be added");
}

unsigned int	Span::shortestSpan()
{	
	if (_nums.empty() || _nums.size() < 2)
		throw std::out_of_range("Can't find shortest span");
	std::sort(_nums.begin(), _nums.end());
	return (0);
}

unsigned int	Span::longestSpan()
{
	if (_nums.empty() || _nums.size() < 2)
		throw std::out_of_range("Can't find longest span");
	std::vector<int>::iterator min = std::min_element(_nums.begin(), _nums.end());
	std::vector<int>::iterator max = std::max_element(_nums.begin(), _nums.end());
	return (abs(*max - *min));
}