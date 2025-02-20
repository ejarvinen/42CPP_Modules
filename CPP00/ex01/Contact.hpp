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

		bool			verifyNameField(std::string text);
		bool			verifyPhoneNumber(std::string text);
		bool			checkForWhiteSpace(std::string text);
		void			addFirstName();
		void			addLastName();
		void			addNickName();
		void			addPhoneNumber();
		void			addSecret();
		void			printField(std::string text);

	public:

		Contact();
		~Contact();

		void			createContact(int index);
		void			printContact();
		unsigned int	getContactID();
		void			printOne();
		
};

#endif