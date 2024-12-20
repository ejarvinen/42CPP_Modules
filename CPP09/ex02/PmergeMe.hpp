/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:10:38 by emansoor          #+#    #+#             */
/*   Updated: 2024/12/20 19:54:26 by emansoor         ###   ########.fr       */
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
		void	mergeVec(int level, int pairs);
		void	insertVec(int level, int pairs);
		void	arrangePairs(int elem1, int elem2, int N);
		void	clearPend(std::vector<int> &main, std::vector<int> &pend, std::vector<int> &pendIndexes, double N);
		void	updateIndexes(std::vector<int> &pendIndexes, int index, double increment);
		void	insertOdd(std::vector<int> &main, std::vector<int> &oddb, double N);
		void	saveMain(std::vector<int> &main);
		void	fillPend(std::vector<int> &pend, std::vector<int> &pendIndexes, double N, int pair);
		void	fillMain(std::vector<int> &main, double N, int pair);
		void	saveOdd(std::vector<int> &oddb, int pairs, double N);

	public:

		PmergeMe();
		PmergeMe(PmergeMe const &copy);
		~PmergeMe();
		PmergeMe	&operator=(PmergeMe const &other);

		void	sortNums(char **argv);

};

// check all exercises for const objects!?

#endif