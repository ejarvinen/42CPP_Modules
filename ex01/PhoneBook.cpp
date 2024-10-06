#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){}
PhoneBook::~PhoneBook(){}

void	PhoneBook::addContact()
{
	this->_contacts[this->_addedContacts % MAX_CONTACT].createContact(this->_addedContacts);
	this->_addedContacts++;
}

void	PhoneBook::printAllContacts()
{
	int		index;

	std::cout << "|" << "        ID" << "|" << "First Name" << "|" << " Last Name" << "|" << "  Nickname" << "|" << std::endl;
	for (index = 0; index < 45; index++)
		std::cout << "=";
	std::cout << std::endl;
	for (index = 0; index < 8; index++)
	{
		this->_contacts[index].printContact();
		std::cout << "|" << std::endl;
	}
}

void	PhoneBook::phoneBook()
{
	std::string	input;

	std::cout << "Welcome to PhoneBook.\nType ADD or SEARCH to add or search contacts. Type EXIT to quit." << std::endl;
	std::cout << "Type ADD, SEARCH or EXIT: ";
	this->_addedContacts = 0;
	getline(std::cin, input);
	while (input.compare("EXIT") != 0)
	{
		if (std::cin.eof())
		{
			std::cout << "Ctrl+D detected. Program exits." << std::endl;
			return ;
		}
		else if (input.compare("ADD") == 0)
		{
			PhoneBook::addContact();
			std::cout << "Added new contact " << std::endl;
		}
		else if (input.compare("SEARCH") == 0)
		{
			PhoneBook::printAllContacts();
		}
		std::cout << "Type ADD, SEARCH or EXIT: ";
		getline(std::cin, input);
	}
	std::cout << "Thank you for using PhoneBook." << std::endl;
}
