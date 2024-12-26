/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:10:38 by emansoor          #+#    #+#             */
/*   Updated: 2024/12/26 19:39:32 by emansoor         ###   ########.fr       */
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
# include <chrono>

class PmergeMe {

	private:

		char				**_unsorted;
		std::vector<int>	_sortedVec;
		std::list<int>		_sortedList;
		std::deque<double>	_jNums;
		double				_vecTime;
		double				_listTime;
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
		void	initElem(std::vector<int> &main, double N, int pair);
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

		/*		LIST FUNCTIONS			*/

		void	runListVersion(void);
		void	insertOdd(void);
		void	insertList(int level, int pairs);
		void	saveMain(std::list<int> &main);
		void	mergeList(int level, int pairs);
		void	insertSingleElems(int nums);
		void	sortElems(int pairs, int level, double N);
		void	addPend(std::list<int> &main, int pend, int pendIndex);
		void	initElem(std::list<int> &main, double N, int pair);
		int		insertNum(std::list<int> &main, std::list<int> &pend, std::list<int> &pendIndexes, int pendIndex);
		void	initPendIndexes(std::list<int> &pendIndexes, double N, int pair);
		void	insertElem(std::list<int> &main, std::list<int> &pend, int pendIndex);
		void	updateIndexes(std::list<int> &pendIndexes, int pendIndex, double increment, int mainIndex);
		void	swapPairs(std::list<int>::iterator elem, std::list<int>::iterator prev, int N);
		void	jstahlInsert(std::list<int> &main, std::list<int> &pend, std::list<int> &pendIndexes, double N);
		void	jstahlInsertSingles(std::list<int> &main, std::list<int> &pend, std::list<int> &pendIndexes);
		void	splitElems(std::list<int> &main, std::list<int> &pend, std::list<int> &pendIndexes, int pairs, double N);

		/*		OUTPUT		*/

		void	printStats(void);

	public:

		PmergeMe();
		PmergeMe(PmergeMe const &copy);
		~PmergeMe();
		PmergeMe	&operator=(PmergeMe const &other);

		void	sortNums(char **argv);

};

#endif