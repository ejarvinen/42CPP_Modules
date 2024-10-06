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
	int		max_contact;

	std::cout << std::endl;
	std::cout << "|" << "        ID" << "|" << "First Name" << "|" << " Last Name" << "|" << "  Nickname" << "|" << std::endl;
	for (index = 0; index < 45; index++)
		std::cout << "=";
	std::cout << std::endl;
	if (this->_addedContacts < MAX_CONTACT)
		max_contact = _addedContacts;
	else
		max_contact = MAX_CONTACT;
	for (index = 0; index < max_contact; index++)
	{
		this->_contacts[index].printContact();
		std::cout << "|" << std::endl;
	}
	std::cout << std::endl;
}

bool	PhoneBook::isNumeric(std::string searchID)
{
	int				index;
	unsigned int	chr;

	if (searchID[0] == '0' && searchID.length() > 1)
		return (false);
	for (index = 0; searchID[index]; index++)
	{
		chr = (unsigned int) searchID[index];
		if (!std::isdigit(chr))
			return (false);
	}
	return (true);
}

void	PhoneBook::findContact(unsigned int searchID)
{
	unsigned int	index;

	for (index = 0; index < MAX_CONTACT; index++)
	{
		if (this->_contacts[index].getContactID() == searchID)
		{
			this->_contacts[index].printOne();
			return ;
		}
	}
	std::cout << "No contacts matching this ID. Please try again." << std::endl;
}

void	PhoneBook::searchContacts()
{
	std::string		searchID;
	unsigned int 	convertedID;

	std::cout << "Enter contact ID or type QUIT to exit SEARCH: ";
	getline(std::cin, searchID);
	while (searchID.compare("QUIT") != 0)
	{
		if (std::cin.eof())
		{
			std::cout << "Ctrl+D detected. Program exits." << std::endl;
			std::exit(1);
		}
		else if (this->isNumeric(searchID))
		{
			try
			{
				convertedID = (unsigned int) std::stoi(searchID);
				if (convertedID < this->_addedContacts)
					this->findContact(convertedID);
				else
					std::cout << "No contacts matching this ID. Please try again." << std::endl;
			}
			catch (const std::out_of_range &e)
			{
				std::cout << "No contacts matching this ID. Please try again." << std::endl;
			}
		}
		std::cout << "Enter contact ID or type QUIT to exit SEARCH: ";
		getline(std::cin, searchID);
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
			this->addContact();
			std::cout << "Added new contact" << std::endl;
		}
		else if (input.compare("SEARCH") == 0)
		{
			this->printAllContacts();
			this->searchContacts();
		}
		std::cout << "Type ADD, SEARCH or EXIT: ";
		getline(std::cin, input);
	}
	std::cout << "Thank you for using PhoneBook." << std::endl;
}
