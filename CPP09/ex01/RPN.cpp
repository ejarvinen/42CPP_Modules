/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:24:29 by emansoor          #+#    #+#             */
/*   Updated: 2025/01/09 18:59:35 by emansoor         ###   ########.fr       */
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

int	RPN::isOperand(std::string arg)
{
	int	value;
	
	for (int index = 0; arg[index]; index++)
	{
		if (std::isdigit(arg[index]) == 0)
			return (2);
	}
	try
	{
		value = std::stoi(arg);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: element not representable as int" << std::endl;
		return (1);
	}
	if (value > 9 || value < 0)
	{
		std::cerr << "Error: number out of range" << std::endl;
		return (1);
	}
	return (0);
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

bool	RPN::overflowCheck(int *res, int first, int scnd, int operation)
{
	if (operation == 1)
	{
		*res = scnd + first;
		if (scnd > 0 && first > 0 && *res < 0)
			return (false);
	}
	if (operation == 2)
	{
		*res = scnd - first;
		if (scnd < 0 && first < 0 && *res > 0)
			return (false);
	}
	if (operation == 3)
	{
		*res = first * scnd;
		if (first > 0 && scnd > 0 && *res < 0)
			return (false);
	}
	if (operation == 4)
	{
		*res = scnd / first;
	}
	return (true);
}

int	RPN::performOperation(std::string arg)
{
	int		first;
	int		scnd;
	int		res;
	bool	overflow;

	if (_stack.empty() || _stack.size() < 2)
	{
		std::cerr << "Error: faulty input logic" << std::endl;
		return (1);
	}
	first = _stack.top();
	_stack.pop();
	scnd = _stack.top();
	_stack.pop();
	if (arg.compare("+") == 0)
		overflow = overflowCheck(&res, first, scnd, 1);
	else if (arg.compare("-") == 0)
		overflow = overflowCheck(&res, first, scnd, 2);
	else if (arg.compare("*") == 0)
		overflow = overflowCheck(&res, first, scnd, 3);
	else
	{
		if (first == 0)
		{
			std::cerr << "Error: division by zero" << std::endl;
			return (1);
		}
		overflow = overflowCheck(&res, first, scnd, 4);
	}
	if (!overflow)
	{
		std::cerr << "Error: result overflows" << std::endl;
		return (1);
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
	int					operandType;			
	
	while (getline(ss, arg, del))
	{
		operandType = isOperand(arg);
		if (operandType == 1)
			return ;
		if (operandType == 0)
		{
			pushOntoStack(arg);
		}
		else if (isOperator(arg) && operandType != 0) // check this condition
		{
			if (argCount == 0)
			{
				std::cerr << "Error: faulty input logic" << std::endl;
				return ;
			}
			if (performOperation(arg))
				return ;
		}
		else if (operandType > 1) // and this
		{
			std::cerr << "Error: suspicious input" << std::endl;
			return ;
		}
		argCount++;
	}
	if (_stack.size() != 1)
	{
		std::cerr << "Error: faulty input logic" << std::endl;
		return ;
	}
	std::cout << _stack.top() << std::endl;
}
