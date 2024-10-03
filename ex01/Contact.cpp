#include "Contact.hpp"

void	Contact::setContact_id(unsigned int i)
{
	this->contact_id = i;
}

int		Contact::getContact_id()
{
	return (this->contact_id);
}

void	Contact::setFirst_name(std::string firstname)
{
	this->first_name = firstname;
}

std::string		Contact::getFirst_name()
{
	return (this->first_name);
}

void	Contact::setLast_name(std::string lastname)
{
	this->last_name = lastname;
}

std::string		Contact::getLast_name()
{
	return (this->last_name);
}

void	Contact::setNickname(std::string nick_name)
{
	this->nickname = nick_name;
}

std::string		Contact::getNickname()
{
	return (this->nickname);
}

void	Contact::setPhoneNumber(unsigned int phonenumber)
{
	this->phone_number = phonenumber;
}

unsigned int	Contact::getPhoneNumber()
{
	return (this->phone_number);
}

void	Contact::setDarkestSecret(std::string secret)
{
	this->darkest_secret = secret;
}

std::string		Contact::getDarkestSecret()
{
	return (this->darkest_secret);
}