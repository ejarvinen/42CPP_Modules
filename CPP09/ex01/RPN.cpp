/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:24:29 by emansoor          #+#    #+#             */
/*   Updated: 2024/12/12 15:51:39 by emansoor         ###   ########.fr       */
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

bool	RPN::isOperand(std::string arg)
{
	int	value;
	
	for (int index = 0; arg[index]; index++)
	{
		if (std::isdigit(arg[index]) == 0)
			return (false);
	}
	try
	{
		value = std::stoi(arg);
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: number out of range" << std::endl;
		return (false);
	}
	if (value > 9 || value < 0)
	{
		std::cout << "Error: number out of range" << std::endl;
		return (false);
	}
	return (true);
}

bool	RPN::isOperator(std::string arg)
{
	if (arg.compare("+") == 0
		|| arg.compare("-") == 0
		|| arg.compare("*") == 0
		|| arg.compare("/") == 0)
		return (true);
	return (false);
}

void	RPN::pushOntoStack(std::string arg)
{
	int	operand;

	operand = std::stoi(arg);
	_stack.push(operand);
}

int	RPN::performOperation(std::string arg)
{
	int	first;
	int	scnd;
	int	res;

	if (_stack.empty() || _stack.size() < 2)
		return (1);
	first = _stack.top();
	_stack.pop();
	scnd = _stack.top();
	_stack.pop();
	if (arg.compare("+") == 0)
		res = scnd + first;
	else if (arg.compare("-") == 0)
		res = scnd - first;
	else if (arg.compare("*") == 0)
		res = first * scnd;
	else
	{
		if (first == 0)
		{
			std::cout << "Error: division by zero" << std::endl;
			return (1);
		}
		res = scnd / first;
	}
	_stack.push(res);
	return (0);
}

void	RPN::processExpression(std::string args)
{
	std::stringstream	ss(args);
	std::string			arg;
	int					argCount = 0;
	char				del = ' ';
	
	while (getline(ss, arg, del))
	{
		if (isOperand(arg))
		{
			pushOntoStack(arg);
		}
		else if (isOperator(arg))
		{
			if (argCount == 0 || performOperation(arg))
			{
				std::cout << "Error: faulty input logic" << std::endl;
				return ;
			}
		}
		else
		{
			std::cout << "Error: suspicious input" << std::endl;
			return ;
		}
		argCount++;
	}
	if (_stack.size() != 1)
	{
		std::cout << "Error: faulty input logic" << std::endl;
		return ;
	}
	std::cout << _stack.top() << std::endl;
}
