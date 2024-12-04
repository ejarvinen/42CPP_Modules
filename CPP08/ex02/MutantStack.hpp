/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:20:42 by emansoor          #+#    #+#             */
/*   Updated: 2024/12/04 15:19:17 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H

# include <stack>
# include <deque>

template <class T, class container=std::deque<T>> // should work with list or vector too
class MutantStack : public std::stack<T> {

	public:

		MutantStack();
		MutantStack(MutantStack const &copy);
		~MutantStack();
		MutantStack &operator=(MutantStack const &other);

		typedef typename container::iterator iterator;
		iterator	begin();
		iterator	end();

};


# include "MutantStack.tpp"

#endif