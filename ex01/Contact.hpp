#ifndef CONTACT_H
# define CONTACT_H

# include <string>

class Contact {

	private:

		unsigned int	contact_id;
		std::string 	first_name;
		std::string		last_name;
		std::string		nickname;
		unsigned int	phone_number;
		std::string		darkest_secret;

	public:

		Contact(){}
		~Contact(){}

		void			setContact_id(unsigned int i);
		int				getContact_id();
		void			setFirst_name(std::string firstname);
		std::string		getFirst_name();
		void			setLast_name(std::string lastname);
		std::string		getLast_name();
		void			setNickname(std::string nickname);
		std::string		getNickname();
		void			setPhoneNumber(unsigned int phonenumber);
		unsigned int	getPhoneNumber();
		void			setDarkestSecret(std::string secret);
		std::string		getDarkestSecret();
};

#endif