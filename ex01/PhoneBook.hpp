#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <string>
# include "Contact.hpp"

class PhoneBook {
	
	private:

		Contact	contacts[8];

	public:

		PhoneBook(){}
		~PhoneBook(){}

		void	phoneBook();
		void	addContact();
};

#endif