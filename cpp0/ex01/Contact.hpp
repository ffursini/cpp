#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string	darkestNecret;
		int			index;


	public:
		Contact();
		~Contact();
		void setContact(int index);
		void displayContact(void);
		void displayFullContact(void);
		std::string truncString(std::string str);
};

#endif
