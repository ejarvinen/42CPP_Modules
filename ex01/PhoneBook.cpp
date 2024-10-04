#include <iostream>
#include "PhoneBook.hpp"

/*
SEARCH loop:
- search by index

ADD loop:
- prompt for each field and save
*/



void	PhoneBook::phoneBook()
{
	std::string	input;

	std::cout << "Welcome to PhoneBook.\nType ADD or SEARCH to add or search contacts.\nType EXIT to quit.\n";
	std::cout << "Type ADD, SEARCH or EXIT: ";
	getline(std::cin, input);
	while (input.compare("EXIT") != 0)
	{
		if (std::cin.eof())
		{
			std::cout << "Ctrl+D detected. Program exits.\n";
			return ;
		}
		else if (input.compare("ADD") == 0)
		{
			std::cout << "Yay, we came to add stuff!\n";
			//add new contact;
		}
		else if (input.compare("SEARCH") == 0)
		{
			std::cout << "Omg there's nothing to search for, teehee\n";
			// go search contacts;
		}
		std::cout << "Type ADD, SEARCH or EXIT: ";
		getline(std::cin, input);
	}
	std::cout << "Thank you for using PhoneBook.\n";
}
