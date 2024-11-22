/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:29:04 by emansoor          #+#    #+#             */
/*   Updated: 2024/11/22 11:07:32 by emansoor         ###   ########.fr       */
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
Array<T>::Array(Array const &copy) : _size(copy.size())
{	
	try
	{
		_a = new T[_size];
		if (_a)
		{
			for (unsigned int index = 0; index < _size; index++)
				_a[index] = copy._a[index];
		}
	}
	catch (std::bad_alloc &ba)
	{
		std::cout << "Failed to allocate memory for size " << _size << " array" << std::endl;
	}
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
	if (this != &other)
	{
		_size = other.size();
		try
		{
			_a = new T[_size];
			if (_a)
			{
				for (unsigned int index = 0; index < _size; index++)
					_a[index] = other._a[index];
			}
		}
		catch (std::bad_alloc &ba)
		{
			std::cout << "Failed to allocate memory for size " << _size << " array" << std::endl;
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
unsigned int	Array<T>::size() const
{
	return (_size);
}
