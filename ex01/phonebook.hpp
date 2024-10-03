#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <string>

class PhoneBook {
	
	public:

		Contact	contacts[8];
};

class Contact {

	public:

		int				contact_id;
		std::string 	first_name;
		std::string		last_name;
		std::string		nickname;
		unsigned int	phone_number;
		std::string		darkest_secret;
};

#endif