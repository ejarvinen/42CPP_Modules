#ifndef CONTACT_H
# define CONTACT_H

# include <string>
# include <iostream>

# define COL_WIDTH 10

class Contact {

	private:

		unsigned int	_contactId;
		std::string 	_firstName;
		std::string		_lastName;
		std::string		_nickName;
		std::string		_phoneNumber;
		std::string		_darkestSecret;

	public:

		Contact(){}
		~Contact(){}

		void	createContact(int index);
		bool	verifyNameField(std::string text);
		bool	verifyPhoneNumber(std::string text);
		void	printContact();
		void	printField(std::string text);
};

#endif