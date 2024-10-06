#include "Contact.hpp"

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

void	Contact::createContact(int index)
{
	this->_contactId = index;
	std::cout << "Enter first name: ";
	getline(std::cin, this->_firstName);
	if (std::cin.eof())
	{
		std::cout << "Ctrl+D detected. Program exits." << std::endl;
		std::exit(1);
	}
	while (!verifyNameField(this->_firstName))
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Please enter a valid first name: ";
		std::cin >> this->_firstName;
	}
	std::cout << "Enter last name: ";
	getline(std::cin, this->_lastName);
	if (std::cin.eof())
	{
		std::cout << "Ctrl+D detected. Program exits." << std::endl;
		std::exit(1);
	}
	while (!verifyNameField(this->_lastName))
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Please enter a valid last name: ";
		std::cin >> this->_lastName;
	}
	std::cout << "Enter nickname: ";
	getline(std::cin, this->_nickName);
	if (std::cin.eof())
	{
		std::cout << "Ctrl+D detected. Program exits." << std::endl;
		std::exit(1);
	}
	while (this->_nickName.empty())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Please enter a valid nickname: ";
		std::cin >> this->_nickName;
	}
	std::cout << "Enter phone number: ";
	getline(std::cin, this->_phoneNumber);
	if (std::cin.eof())
	{
		std::cout << "Ctrl+D detected. Program exits." << std::endl;
		std::exit(1);
	}
	while (!verifyPhoneNumber(this->_phoneNumber))
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Please enter a valid phone number: ";
		std::cin >> this->_phoneNumber;
	}
	std::cout << "Enter darkest secret: ";
	getline(std::cin, this->_darkestSecret);
	if (std::cin.eof())
	{
		std::cout << "Ctrl+D detected. Program exits." << std::endl;
		std::exit(1);
	}
	while (this->_darkestSecret.empty())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Please enter a valid secret: ";
		std::cin >> this->_darkestSecret;
	}
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
	Contact::printField(id);
	Contact::printField(this->_firstName);
	Contact::printField(this->_lastName);
	Contact::printField(this->_nickName);
}
