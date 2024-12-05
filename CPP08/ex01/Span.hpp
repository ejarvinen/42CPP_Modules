/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:12:47 by emansoor          #+#    #+#             */
/*   Updated: 2024/12/05 14:40:34 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
# define SPAN_H

# include <vector>
# include <iostream>
# include <algorithm>

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
		void			addNumbers(std::vector<int>::iterator start, std::vector<int>::iterator end);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();
		void			printMinMax();

};


#endif