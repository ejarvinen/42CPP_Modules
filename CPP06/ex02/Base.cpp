/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:33:50 by emansoor          #+#    #+#             */
/*   Updated: 2024/11/14 14:35:10 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base	*generate(void)
{
	int		randomizer;
	Base	*randomPtr;

	randomizer = rand() % 100;
	if (randomizer % 3 == 0)
	{
		try
		{
			randomPtr = new A();
		}
		catch (...)
		{
			std::cout << "Failed to allocate class A object" << std::endl;
		}
	}
	else if (randomizer % 3 == 1)
	{
		try
		{
			randomPtr = new B();
		}
		catch (...)
		{
			std::cout << "Failed to allocate class B object" << std::endl;
		}
	}
	else
	{
		try
		{
			randomPtr = new C();
		}
		catch (...)
		{
			std::cout << "Failed to allocate class C object" << std::endl;
		}
	}
	return (randomPtr);
}

void	identify(Base *p)
{
	A	*a;
	B	*b;
	C	*c;

	a = dynamic_cast<A*>(p);
	if (a)
	{
		std::cout << "A" << std::endl;
		return ;
	}
	b = dynamic_cast<B*>(p);
	if (b)
	{
		std::cout << "B" << std::endl;
		return ;
	}
	c = dynamic_cast<C*>(p);
	if (c)
	{
		std::cout << "C" << std::endl;
		return ;
	}
}

void	identify(Base &p)
{	
	try
	{
		(void)dynamic_cast<A&>(p);
	}
	catch (std::bad_cast const &ex)
	{
		try
		{
			(void)dynamic_cast<B&>(p);
		}
		catch (std::bad_cast const &ex)
		{
			try
			{
				(void)dynamic_cast<C&>(p);
			}
			catch (std::bad_cast const &ex)
			{
				std::cout << "Unrecognizable Base type" << std::endl;
				return ;
			}
			std::cout << "C" << std::endl;
			return ;
		}
		std::cout << "B" << std::endl;
		return ;
	}
	std::cout << "A" << std::endl;
}
