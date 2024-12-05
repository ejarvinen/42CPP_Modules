/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 09:10:27 by emansoor          #+#    #+#             */
/*   Updated: 2024/12/05 14:27:02 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <class T, class container>
MutantStack<T, container>::MutantStack() : std::stack<T>()
{}

template <class T, class container>
MutantStack<T, container>::MutantStack(MutantStack const &copy) : std::stack<T>(copy)
{}

template <class T, class container>
MutantStack<T, container>::~MutantStack()
{}

template <class T, class container>
MutantStack<T, container>	&MutantStack<T, container>::operator=(MutantStack const &other)
{
	if (this != &other)
	{
		std::stack<T>::operator=(other);
	}
	return (*this);
}

template <class T, class container>
typename MutantStack<T, container>::iterator	MutantStack<T, container>::begin()
{
	return (this->c.begin());
}

template <class T, class container>
typename MutantStack<T, container>::iterator	MutantStack<T, container>::begin() const
{
	return (this->c.begin());
}

template <class T, class container>
typename MutantStack<T, container>::iterator	MutantStack<T, container>::end()
{
	return (this->c.end());
}

template <class T, class container>
typename MutantStack<T, container>::iterator	MutantStack<T, container>::end() const
{
	return (this->c.end());
}
