/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 10:45:04 by emansoor          #+#    #+#             */
/*   Updated: 2024/10/14 15:28:35 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed(const int param)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = param << this->fbits;
}

Fixed::Fixed(const float param)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = param * (float)(1 << this->fbits);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &overloadCopy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &overloadCopy)
	{
		value = overloadCopy.getRawBits();
	}
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	return (this->value);
}

void	Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

float	Fixed::toFloat(void) const
{
	float	temp;

	temp = this->value / (float)(1 << this->fbits);
	return (temp);
}

int	Fixed::toInt(void) const
{
	return (this->value >> this->fbits);
}

std::ostream&	operator<<(std::ostream &out, const Fixed &obj)
{
	out << obj.toFloat();
	return (out);
}
