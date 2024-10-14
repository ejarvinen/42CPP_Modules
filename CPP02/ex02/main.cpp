/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:56:26 by emansoor          #+#    #+#             */
/*   Updated: 2024/10/14 15:26:51 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed 		a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	return (0);
}

/* int main(void)
{
	Fixed 	a(-1);
	Fixed	b(7);
	Fixed	c(2.3f);
	bool	res;

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << std::endl;

	res = a == b;
	std::cout << "res (a==b): "  << res << std::endl;
	std::cout << std::endl;

	res = a != b;
	std::cout << "res (a!=b): "  << res << std::endl;
	std::cout << std::endl;

	res = a > b;
	std::cout << "res (a>b): "  << res << std::endl;
	std::cout << std::endl;

	res = a < b;
	std::cout << "res (a<b): "  << res << std::endl;
	std::cout << std::endl;

	res = a >= b;
	std::cout << "res (a>=b): "  << res << std::endl;
	std::cout << std::endl;

	res = a <= b;
	std::cout << "res (a<=b): "  << res << std::endl;
	std::cout << std::endl;

	std::cout << "c - b: " << c - b << std::endl;
	std::cout << std::endl;

	std::cout << "a + c: " << a + c << std::endl;
	std::cout << std::endl;

	std::cout << "b * c: " << b * c << std::endl;
	std::cout << std::endl;

	std::cout << "b / c: " << b / c << std::endl;
	std::cout << std::endl;

	return (0);
} */