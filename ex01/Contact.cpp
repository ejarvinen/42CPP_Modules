#include "Contact.hpp"

Contact::Contact(){}
Contact::~Contact(){}

bool	Contact::verifyNameField(std::string text)
{
	int				index;
	unsigned int	chr;

	if (text.empty() || text.length() < 2)
		return (false);
	for (index = 0; text[index]; index++)
	{
		chr = text[index];
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
		chr = text[index];
		if (!std::isdigit(chr))
			return (false);
	}
	return (true);
}

bool	Contact::checkForWhiteSpace(std::string text)
{
	unsigned int	chr;

	chr = text[0];
	if (text.empty() || std::isspace(chr))
		return (false);
	return (true);
}

void	Contact::addFirstName()
{
	std::string	*firstname = &this->_firstName;

	std::cout << "Enter first name: ";
	getline(std::cin, *firstname);
	while (!verifyNameField(*firstname))
	{
		if (std::cin.eof())
		{
			std::cout << "Ctrl+D detected. Program exits." << std::endl;
			std::exit(1);
		}
		std::cin.clear();
		std::cout << "Please enter a valid first name: ";
		getline(std::cin, *firstname);
	}
}

void	Contact::addLastName()
{
	std::string	*lastname = &this->_lastName;

	std::cout << "Enter last name: ";
	getline(std::cin, *lastname);
	while (!verifyNameField(*lastname))
	{
		if (std::cin.eof())
		{
			std::cout << "Ctrl+D detected. Program exits." << std::endl;
			std::exit(1);
		}
		std::cin.clear();
		std::cout << "Please enter a valid last name: ";
		getline(std::cin, *lastname);
	}
}

void	Contact::addNickName()
{
	std::string	*nickname = &this->_nickName;

	std::cout << "Enter nickname: ";
	getline(std::cin, *nickname);
	while (!checkForWhiteSpace(*nickname))
	{
		if (std::cin.eof())
		{
			std::cout << "Ctrl+D detected. Program exits." << std::endl;
			std::exit(1);
		}
		std::cin.clear();
		std::cout << "Please enter a valid nickname: ";
		getline(std::cin, *nickname);
	}
}

void	Contact::addPhoneNumber()
{
	std::string	*phonenumber = &this->_phoneNumber;

	std::cout << "Enter phone number: ";
	getline(std::cin, *phonenumber);
	while (!verifyPhoneNumber(*phonenumber))
	{
		if (std::cin.eof())
		{
			std::cout << "Ctrl+D detected. Program exits." << std::endl;
			std::exit(1);
		}
		std::cin.clear();
		std::cout << "Please enter a valid phone number: ";
		getline(std::cin, *phonenumber);
	}
}

void	Contact::addSecret()
{
	std::string	*secret = &this->_darkestSecret;

	std::cout << "Enter darkest secret: ";
	getline(std::cin, *secret);
	while (!checkForWhiteSpace(*secret))
	{
		if (std::cin.eof())
		{
			std::cout << "Ctrl+D detected. Program exits." << std::endl;
			std::exit(1);
		}
		std::cin.clear();
		std::cout << "Please enter a valid secret: ";
		getline(std::cin, *secret);
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
