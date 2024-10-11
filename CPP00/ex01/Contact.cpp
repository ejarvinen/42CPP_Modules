#include "Contact.hpp"

Contact::Contact(){}
Contact::~Contact(){}

unsigned int	Contact::getContactID()
{
	return (this->_contactId);
}

bool	Contact::verifyNameField(std::string text)
{
	int				index;
	unsigned int	chr;

	if (text.empty() || text.length() < 2)
		return (false);
	for (index = 0; text[index]; index++)
	{
		chr = (unsigned int) text[index];
		if (!std::isalpha(chr))
			return (false);
	}
	return (true);
}

bool	Contact::verifyPhoneNumber(std::string text)
{
	int				index;
	unsigned int	chr;

	if (text.empty() || text.length() != 10)
		return (false);
	for (index = 0; text[index]; index++)
	{
		chr = (unsigned int) text[index];
		if (!std::isdigit(chr))
			return (false);
	}
	return (true);
}

bool	Contact::checkForWhiteSpace(std::string text)
{
	unsigned int	chr;

	chr = (unsigned int) text[0];
	if (text.empty() || std::isspace(chr))
		return (false);
	return (true);
}

void	Contact::addFirstName()
{
	std::cout << "Enter first name: ";
	getline(std::cin, this->_firstName);
	while (!verifyNameField(this->_firstName))
	{
		if (std::cin.eof())
		{
			std::cout << "Ctrl+D detected. Program exits." << std::endl;
			std::exit(1);
		}
		std::cin.clear();
		std::cout << "Please enter a valid first name: ";
		getline(std::cin, this->_firstName);
	}
}

void	Contact::addLastName()
{
	std::cout << "Enter last name: ";
	getline(std::cin, this->_lastName);
	while (!verifyNameField(this->_lastName))
	{
		if (std::cin.eof())
		{
			std::cout << "Ctrl+D detected. Program exits." << std::endl;
			std::exit(1);
		}
		std::cin.clear();
		std::cout << "Please enter a valid last name: ";
		getline(std::cin, this->_lastName);
	}
}

void	Contact::addNickName()
{
	std::cout << "Enter nickname: ";
	getline(std::cin, this->_nickName);
	while (!checkForWhiteSpace(this->_nickName))
	{
		if (std::cin.eof())
		{
			std::cout << "Ctrl+D detected. Program exits." << std::endl;
			std::exit(1);
		}
		std::cin.clear();
		std::cout << "Please enter a valid nickname: ";
		getline(std::cin, this->_nickName);
	}
}

void	Contact::addPhoneNumber()
{
	std::cout << "Enter phone number: ";
	getline(std::cin, this->_phoneNumber);
	while (!verifyPhoneNumber(this->_phoneNumber))
	{
		if (std::cin.eof())
		{
			std::cout << "Ctrl+D detected. Program exits." << std::endl;
			std::exit(1);
		}
		std::cin.clear();
		std::cout << "Please enter a valid phone number: ";
		getline(std::cin, this->_phoneNumber);
	}
}

void	Contact::addSecret()
{
	std::cout << "Enter darkest secret: ";
	getline(std::cin, this->_darkestSecret);
	while (!checkForWhiteSpace(this->_darkestSecret))
	{
		if (std::cin.eof())
		{
			std::cout << "Ctrl+D detected. Program exits." << std::endl;
			std::exit(1);
		}
		std::cin.clear();
		std::cout << "Please enter a valid secret: ";
		getline(std::cin, this->_darkestSecret);
	}
}

void	Contact::createContact(int index)
{
	this->_contactId = index;

	this->addFirstName();
	this->addLastName();
	this->addNickName();
	this->addPhoneNumber();
	this->addSecret();
}

void	Contact::printField(std::string text)
{
	size_t	index;
	int	i;

	std::cout << "|";
	if (text.length() > COL_WIDTH)
	{
		for (index = 0; index < COL_WIDTH - 1; index++)
			std::cout << text[index];
		std::cout << ".";
	}
	else if (text.length() < COL_WIDTH)
	{
		for (index = 0; index < COL_WIDTH - text.length(); index++)
			std::cout << " ";
		for (i = 0; index + i < COL_WIDTH; i++)
			std::cout << text[i];
	}
	else
	{
		for (index = 0; index < COL_WIDTH; index++)
			std::cout << text[index];
	}
}

void	Contact::printContact()
{
	std::string	id;

	id = std::to_string(this->_contactId);
	this->printField(id);
	this->printField(this->_firstName);
	this->printField(this->_lastName);
	this->printField(this->_nickName);
}

void	Contact::printOne()
{
	std::cout << std::endl;
	std::cout << "Contact ID: " << this->_contactId << std::endl;
	std::cout << "First Name: " << this->_firstName << std::endl;
	std::cout << "Last Name: " << this->_lastName << std::endl;
	std::cout << "Nickname: " << this->_nickName << std::endl;
	std::cout << "Phone Number: " << this->_phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << this->_darkestSecret << std::endl;
	std::cout << std::endl;
}
