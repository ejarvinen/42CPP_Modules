/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:24:34 by emansoor          #+#    #+#             */
/*   Updated: 2024/12/12 15:24:55 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_H
# define RPN_H

# include <stack>
# include <iostream>
# include <sstream>
# include <cctype>

class RPN {

	private:

		std::stack<int>	_stack;
		
		bool	isOperand(std::string arg);
		bool	isOperator(std::string arg);
		void	pushOntoStack(std::string arg);
		int		performOperation(std::string arg);

	public:

		RPN();
		RPN(RPN const &copy);
		~RPN();
		RPN	&operator=(RPN const &other);

		void	processExpression(std::string args);

};

#endif