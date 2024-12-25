/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:10:38 by emansoor          #+#    #+#             */
/*   Updated: 2024/12/25 18:35:06 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_H
# define PMERGEME_H

# include <string>
# include <vector>
# include <list>
# include <deque>
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
		std::deque<double>	_jNums;
		int					_size;
		bool				_even;
		int					_straggler;

		/*		INPUT VALIDATION		*/

		int		checkArgs(char **argv);
		bool	isAllDigits(std::string);

		/*		VECTOR FUNCTIONS		*/

		void	runVectorVersion(void);
		void	sortElements(int pairs, int level, double N);
		void	splitElements(std::vector<int> &main, std::vector<int> &pend, std::vector<int> &pendIndexes, int pairs, double N);
		void	mergeVec(int level, int pairs);
		void	insertVec(int level, int pairs);
		void	arrangePairs(int elem1, int elem2, int N);
		void	insertElem(std::vector<int> &main, std::vector<int> &pend, int pendIndex);
		void	updateIndexes(std::vector<int> &pendIndexes, int pendIndex, double increment, int mainIndex);
		void	initPend(std::vector<int> &pend, double N, int pair);
		void	initMain(std::vector<int> &main, double N, int pair);
		void	saveOdd(std::vector<int> &oddb, int pairs, double N);
		void	initJacobstahl(void);
		double	jacobstahl(double n);
		void	jacobstahlInsert(std::vector<int> &main, std::vector<int> &pend, std::vector<int> &pendIndexes, double N);
		int		getjNumIndex(double pendSize);
		void	insertSingles(int nums);
		void	addOdd(void);
		void	addPend(std::vector<int> &main, int pend, int pendIndex);
		void	saveMain(std::vector<int> &main);
		void	initPendIndexes(std::vector<int> &pendIndexes, double N, int pair);
		int		insertNum(std::vector<int> &main, std::vector<int> &pend, std::vector<int> &pendIndexes, int pendIndex);
		void	jacobstahlInsertSingles(std::vector<int> &main, std::vector<int> &pend, std::vector<int> &pendIndexes);

	public:

		PmergeMe();
		PmergeMe(PmergeMe const &copy);
		~PmergeMe();
		PmergeMe	&operator=(PmergeMe const &other);

		void	sortNums(char **argv);

};

// check all exercises for const objects!?

#endif