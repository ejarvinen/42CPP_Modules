/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:24:26 by emansoor          #+#    #+#             */
/*   Updated: 2024/12/12 12:54:02 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Error: invalid number of arguments" << std::endl;
		return (1);
	}
	RPN	expr;
	expr.processExpression(argv[1]);
	return (0);
}
