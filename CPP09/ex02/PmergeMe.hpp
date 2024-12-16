/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:10:38 by emansoor          #+#    #+#             */
/*   Updated: 2024/12/16 14:43:58 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_H
# define PMERGEME_H

# include <string>
# include <vector>
# include <list>
# include <iostream>
# include <cctype>
# include <algorithm>
# include <cmath>
# include <iterator>

class PmergeMe {

	private:

		char				**_unsorted;
		std::vector<int>	_sortedVec;
		std::list<int>		_sortedList;
		int					_size;
		bool				_even;
		int					_straggler;

		int		checkArgs(char **argv);
		bool	isAllDigits(std::string);
		void	sortVec(int level, int pairs);

	public:

		PmergeMe();
		PmergeMe(PmergeMe const &copy);
		~PmergeMe();
		PmergeMe	&operator=(PmergeMe const &other);

		void	sortNums(char **argv);

};

// check all exercises for const objects!?

#endif