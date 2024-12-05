/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:20:42 by emansoor          #+#    #+#             */
/*   Updated: 2024/12/05 14:26:54 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H

# include <stack>
# include <deque>

template <class T, class container=std::deque<T>>
class MutantStack : public std::stack<T> {

	public:

		MutantStack();
		MutantStack(MutantStack const &copy);
		~MutantStack();
		MutantStack &operator=(MutantStack const &other);

		typedef typename container::iterator iterator;
		iterator	begin();
		iterator	begin() const;
		iterator	end();
		iterator	end() const;

};

# include "MutantStack.tpp"

#endif