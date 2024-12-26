// even number:
// ./PmergeMe 1 3 15 8 14 7 10 5 11 12 13 4 9 0 2 6

// after level 1:
// 1 3 8 15 7 14 5 10 11 12 4 13 0 9 2 6

// after level 2:
// 1 3 8 15 5 10 7 14 11 12 4 13 2 6 0 9

// after level 3:
// 5 10 7 14 1 3 8 15 2 6 0 9 11 12 4 13

// after level 4:
// 2 6 0 9 11 12 4 13 5 10 7 14 1 3 8 15

// insert part
// level 3:
// main: 2 6 0 9 11 12 4 13 1 3 8 15
// pend: 5 10 7 14
// odd: N/A
// after level 3: 2 6 0 9 11 12 4 13 5 10 7 14 1 3 8 15 // FINE

// level 2:
// main: 2 6 0 9 4 13 7 14 8 15
// pend: 11 12 5 10 1 3
// odd: N/A
// after level 2: 1 3 2 6 0 9 5 10 11 12 4 13 7 14 8 15

// level 1:
// main: 1 3 6 9 10 12 13 14 15
// pend: 2 0 5 11 4 7 8
// odd: N/A
// after level 1: sorted

//*******************************************

// even but not enough:
// ./PmergeMe 19 10 1 17 12 13 3 21 8 15 4 18 0 9 11 6 7 14 5 16 2 20

// after level 1:
// 10 19 1 17 12 13 3 21 8 15 4 18 0 9 6 11 7 14 5 16 2 20

// after level 2:
// 1 17 10 19 12 13 3 21 8 15 4 18 0 9 6 11 7 14 5 16 2 20

// after level 3:
// 1 17 10 19 12 13 3 21 0 9 6 11 8 15 4 18 7 14 5 16 2 20

// after level 4:
// 0 9 6 11 8 15 4 18 1 17 10 19 12 13 3 21 7 14 5 16 2 20

//*******************************************

// odd number:
// ./PmergeMe 0 2 1 8 5 4 14 9 10 7 3 6 13 11 12
// straggler = 12

// after level 1:
// 0 2 1 8 4 5 9 14 7 10 3 6 11 13

// after level 2:
// 0 2 1 8 4 5 9 14 3 6 7 10 11 13

// after level 3:
// 0 2 1 8 4 5 9 14 3 6 7 10 11 13

// insert part
// level 3:
// main: 0 2 1 8 4 5 9 14
// pend: 3 6 7 10
// odd: N / A
// after level 3: 0 2 1 8 3 6 7 10 4 5 9 14 11 13

// level 2:
// main: 0 2 1 8 7 10 9 14 
// pend: 3 6 4 5
// odd: 11 13
// after level 2: 

//*******************************************

// 42 example: ./PmergeMe 11 2 17 0 16 8 6 15 10 3 21 1 18 9 14 19 12 5 4 20 13 7

// ./PmergeMe 6 30 10 16 4 22 12 8 9 18 23 27 25 19 26 7 29 3 13 5 1 2 15 20 14 28 21 17 11 24

/* std::cout << "og: ";
	std::vector<int>::iterator end = _sortedVec.end();
	for (std::vector<int>::iterator it = _sortedVec.begin(); it != end; std::advance(it, 1))
		std::cout << *it << " ";
	std::cout << std::endl;
	
	std::cout << "main: ";
	end = main.end();
	for (std::vector<int>::iterator it = main.begin(); it != end; std::advance(it, 1))
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "pend: ";
	end = pend.end();
	for (std::vector<int>::iterator it = pend.begin(); it != end; std::advance(it, 1))
		std::cout << *it << " ";
	std::cout << std::endl;
	
	std::cout << "indexes: ";
	end = pendIndexes.end();
	for (std::vector<int>::iterator it = pendIndexes.begin(); it != end; std::advance(it, 1))
		std::cout << *it << " ";
	std::cout << std::endl;

	if (odd)
	{
		std::cout << "odd: ";
		end = oddb.end();
		for (std::vector<int>::iterator it = oddb.begin(); it != end; std::advance(it, 1))
			std::cout << *it << " ";
		std::cout << std::endl;
	} */

/* std::cout << "og: ";
	std::list<int>::iterator end = _sortedVec.end();
	for (std::list<int>::iterator it = _sortedVec.begin(); it != end; std::advance(it, 1))
		std::cout << *it << " ";
	std::cout << std::endl;
	
	std::cout << "main: ";
	end = main.end();
	for (std::list<int>::iterator it = main.begin(); it != end; std::advance(it, 1))
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "pend: ";
	end = pend.end();
	for (std::list<int>::iterator it = pend.begin(); it != end; std::advance(it, 1))
		std::cout << *it << " ";
	std::cout << std::endl;
	
	std::cout << "indexes: ";
	end = pendIndexes.end();
	for (std::list<int>::iterator it = pendIndexes.begin(); it != end; std::advance(it, 1))
		std::cout << *it << " ";
	std::cout << std::endl;

	if (odd)
	{
		std::cout << "odd: ";
		end = oddb.end();
		for (std::list<int>::iterator it = oddb.begin(); it != end; std::advance(it, 1))
			std::cout << *it << " ";
		std::cout << std::endl;
	} */


/* std::cout << "Jacobstahl numbers:" << std::endl;
	std::deque<double>::iterator it = _jNums.begin();
	std::deque<double>::iterator end = _jNums.end();
	while (it != end)
	{
		std::cout << *it << std::endl;
		std::advance(it, 1);
	} */
