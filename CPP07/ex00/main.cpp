/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:01:25 by emansoor          #+#    #+#             */
/*   Updated: 2024/11/18 13:14:11 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

template <typename T> void	swap(T &param1, T &param2)
{
	T temp;
	
	temp = param1;
	param1 = param2;
	param2 = temp;
}

template <typename T> T	min(T param1, T param2)
{
	T res;

	res = (param1 < param2) ? param1 : param2;
	return (res);
}

template <typename T> T	max(T param1, T param2)
{
	T res;

	res = (param1 > param2) ? param1 : param2;
	return (res);
}

int main( void ) {
	
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	char e = 'e';
	char f = 'f';
	::swap(e, f);
	std::cout << "e = " << e << ", f = " << f << std::endl;
	std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
	std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;
	
	return 0;
}