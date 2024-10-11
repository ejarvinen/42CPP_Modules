#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# define MAX_CONTACT 8

# include "Contact.hpp"

class PhoneBook {
	
	private:

		Contact			_contacts[MAX_CONTACT];
		unsigned int	_addedContacts;

		void	addContact();
		void	printAllContacts();
		void	searchContacts();
		bool	isNumeric(std::string searchID);
		void	findContact(unsigned int searchID);

	public:

		PhoneBook();
		~PhoneBook();
		
		void	phoneBook();
};

#endif