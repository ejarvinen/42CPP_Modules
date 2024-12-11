/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:24:29 by emansoor          #+#    #+#             */
/*   Updated: 2024/12/11 16:36:02 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(RPN const &copy) : _stack(copy._stack) {}

RPN::~RPN() {}

RPN	&RPN::operator=(RPN const &other)
{
	if (this != &other)
	{
		_stack = other._stack;
	}
	return (*this);
}
