/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:26:00 by emansoor          #+#    #+#             */
/*   Updated: 2024/12/05 14:44:12 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void)
{
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

		try
		{
			sp.addNumber(12);
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
	}
	{
		Span sp0 = Span(0);
		try
		{
			sp0.addNumber(1);
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
	}
	{
		Span sp0 = Span(4);

		sp0.addNumber(0);
		sp0.addNumber(0);
		sp0.addNumber(0);
		sp0.addNumber(0);
		std::cout << sp0.shortestSpan() << std::endl;
		std::cout << sp0.longestSpan() << std::endl;
	}
	{
		unsigned int size = 500;
		std::vector<int> add(size);

		srand(time(NULL));
		generate(add.begin(), add.end(), rand);
		
		Span sp1 = Span(size); // try: Span(size - 1)
		try
		{
			sp1.addNumbers(add.begin(), add.end());
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}

		sp1.printMinMax();
		try
		{
			std::cout << sp1.shortestSpan() << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
		try
		{
			std::cout << sp1.longestSpan() << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
	}
	return (0);
}
