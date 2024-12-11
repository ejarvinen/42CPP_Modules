/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:24:34 by emansoor          #+#    #+#             */
/*   Updated: 2024/12/11 16:36:07 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_H
# define RPN_H

# include <stack>

class RPN {

	private:

		std::stack<int>	_stack;

	public:

		RPN();
		RPN(RPN const &copy);
		~RPN();
		RPN	&operator=(RPN const &other);

};

#endif