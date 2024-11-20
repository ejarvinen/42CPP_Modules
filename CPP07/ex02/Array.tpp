/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:29:04 by emansoor          #+#    #+#             */
/*   Updated: 2024/11/20 15:55:39 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <class T>
Array<T>::Array() : _size(0)
{
	try
	{
		_a = new T[0];
	}
	catch (std::bad_alloc &ba)
	{
		std::cout << "Failed to allocate memory for default sized array" << std::endl;
	}
}

template <class T>
Array<T>::Array(unsigned int n) : _size(n)
{
	try
	{
		_a = new T[n];
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
	
	if (_a)
	{
		if (copy._a)
			delete[] copy._a;
		try
		{
			copy._a = new T[_size];
			if (copy._a)
			{
				for (index = 0; index < _size; index++)
					copy._a[index] = _a[index];
			}
		}
		catch (std::bad_alloc &ba)
		{
			std::cout << "Failed to allocate memory for size " << _size << " array" << std::endl;
		}
	}
	*this = copy;
}

template <class T>
Array<T>::~Array()
{
	if (_a)
	{
		delete[] _a;
	}
}

template <class T>
Array<T>	&Array<T>::operator=(Array const &other)
{
	unsigned int	index;
	
	if (this != &other)
	{
		if (_a)
		{
			if (other._a)
				delete[] other._a;
			try
			{
				other._a = new T[_size];
				if (other._a)
				{
					for (index = 0; index < _size; index++)
						other._a[index] = _a[index];
				}
			}
			catch (std::bad_alloc &ba)
			{
				std::cout << "Failed to allocate memory for size " << _size << " array" << std::endl;
			}
		}
	}
	return (*this);
}

template <class T>
T	&Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw std::out_of_range("Index out of range");
	return (_a[index]);
}


template <class T>
unsigned int	Array<T>::size()
{
	return (_size);
}
