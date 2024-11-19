/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:29:04 by emansoor          #+#    #+#             */
/*   Updated: 2024/11/19 12:19:32 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <class T>
Array<T>::Array()
{
	try
	{
		a = new T[0];
	}
	catch (std::bad_alloc &ba)
	{
		std::cout << "Failed to allocate memory for default sized array" << std::endl;
	}
}

template <class T>
Array<T>::Array(unsigned int n)
{
	try
	{
		a = new T[n];
	}
	catch (std::bad_alloc &ba)
	{
		std::cout << "Failed to allocate memory for size " << n << " array" << std::endl;
	}
}

template <class T>
Array<T>::Array(Array const &copy)
{
	unsigned int	index;
	unsigned int	size;
	
	if (a && copy.a)
	{
		size = this->size();
		for (index = 0; index < size; index++)
		{
			try
			{
				a[index] = copy.a[index];
			}
			catch (...)
			{
				break ;
			}
		}
	}
	*this = copy;
}

template <class T>
Array<T>::~Array()
{
	if (a)
	{
		delete[] a;
	}
}

template <class T>
Array<T>	&Array<T>::operator=(Array const &other)
{
	unsigned int	index;
	unsigned int	size;
	
	if (this != &other)
	{
		if (a && other.a)
		{
			size = this->size();
			for (index = 0; index < size; index++)
			{
				try
				{
					a[index] = other.a[index];
				}
				catch (...)
				{
					break ;
				}
			}
		}
	}
	return (*this);
}

template <class T>
unsigned int	Array<T>::size()
{
	unsigned int	size = 0;

	if (a)
	{
		while (true)
		{
			try
			{
				a[size];
			}
			catch (...)
			{
				break ;
			}
			size++;
		}
	}
	return (size);
}
