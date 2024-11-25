/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:12:47 by emansoor          #+#    #+#             */
/*   Updated: 2024/11/25 15:51:33 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
# define SPAN_H

# include <vector>
# include <iostream>
# include <algorithm>
# include <cmath>

class Span {

	private:
		
		std::vector<int>	_nums;
		unsigned int		_N;

	public:

		Span();
		Span(unsigned int N);
		Span(Span const &copy);
		~Span();
		Span &operator=(Span const &other);

		void			addNumber(int newNbr);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();

};


#endif