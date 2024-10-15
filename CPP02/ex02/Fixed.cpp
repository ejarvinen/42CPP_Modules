/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 10:45:04 by emansoor          #+#    #+#             */
/*   Updated: 2024/10/15 11:55:53 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->value = 0;
}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
}

Fixed::Fixed(const int param)
{
	this->value = param << this->fbits;
}

Fixed::Fixed(const float param)
{
	this->value = roundf(param * (float)(1 << this->fbits));
}

Fixed::~Fixed()
{}

Fixed	&Fixed::operator=(const Fixed &other)
{
	if (this != &other)
	{
		value = other.getRawBits();
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

/********************COMPARISON OVERLOADS********************/

bool	Fixed::operator==(Fixed &other)
{
	return (this->getRawBits() == other.getRawBits());
}

bool	Fixed::operator!=(Fixed &other)
{
	return (!(*this == other));
}

bool	Fixed::operator<(Fixed &other)
{
	return (this->getRawBits() < other.getRawBits());
}

bool	Fixed::operator>(Fixed &other)
{
	return (!(*this < other));
}

bool	Fixed::operator<=(Fixed &other)
{
	return (this->getRawBits() <= other.getRawBits());
}

bool	Fixed::operator>=(Fixed &other)
{
	return (this->getRawBits() >= other.getRawBits());
}

/********************ARITHMETIC OVERLOADS********************/

float	Fixed::operator+(Fixed other)
{
	float	result;

	result = this->toFloat() + other.toFloat();
	return (result);
}

float	Fixed::operator-(Fixed other)
{
	float	result;

	result = this->toFloat() - other.toFloat();
	return (result);
}

float	Fixed::operator*(Fixed other)
{
	float	result;

	result = this->toFloat() * other.toFloat();
	return (result);
}

float	Fixed::operator/(Fixed other)
{
	float	result;

	result = this->toFloat() / other.toFloat();
	return (result);
}

/********************INCREMENT/DECREMENT OVERLOADS********************/

Fixed	Fixed::operator++()
{
	float	res;

	res = this->getRawBits() + 1;
	this->value = res;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	float	res;
	Fixed	temp;

	temp = *this;
	res = this->getRawBits() + 1;
	this->value = res;
	return (temp);
}

Fixed	Fixed::operator--()
{
	float	res;

	res = this->getRawBits() - 1;
	this->value = res;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	float	res;
	Fixed	temp;

	temp = *this;
	res = this->getRawBits() - 1;
	this->value = res;
	return (temp);
}

/********************MIN/MAX OVERLOADS********************/

Fixed		&Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1.getRawBits() > f2.getRawBits())
		return (f2);
	return (f1);
}

const Fixed	&Fixed::min(const Fixed &f1, const Fixed &f2)
{
	if (f1.getRawBits() > f2.getRawBits())
		return (f2);
	return (f1);
}

Fixed		&Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1.getRawBits() >= f2.getRawBits())
		return (f1);
	return (f2);
}

const Fixed	&Fixed::max(const Fixed &f1, const Fixed &f2)
{
	if (f1.getRawBits() >= f2.getRawBits())
		return (f1);
	return (f2);
}

/********************INSERTION OPERATOR OVERLOAD********************/

std::ostream&	operator<<(std::ostream &out, const Fixed &obj)
{
	out << obj.toFloat();
	return (out);
}
