#include "Contact.hpp"

Contact::Contact()
{
	this->index = -1;
	this->firstName = "";
	this->lastName = "";
	this->nickname = "";
	this->phoneNumber = "";
	this->darkestNecret = "";
}
Contact::~Contact()
{
}

void	Contact::setContact(int index)
{
	this->index = index;
	std::cout << "Enter first name: ";
	std::getline(std::cin, this->firstName);
	std::cout << "Enter last name: ";
	std::getline(std::cin, this->lastName);
	std::cout << "Enter nickname: ";
	std::getline(std::cin, this->nickname);
	std::cout << "Enter phone number: ";
	std::getline(std::cin, this->phoneNumber);
	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, this->darkestNecret);
	if (this->firstName.empty() || this->lastName.empty() || this->nickname.empty() || this->phoneNumber.empty() || this->darkestNecret.empty())
		this->index = -1;
}

void	Contact::displayContact(void)
{
	if (this->index == -1)
		return ;
	std::cout << "|" << std::setw(10) << this->index;
	std::cout << "|" << std::setw(10) << this->truncString(this->firstName);
	std::cout << "|" << std::setw(10) << this->truncString(this->lastName);
	std::cout << "|" << std::setw(10) << this->truncString(this->nickname);
	std::cout << "|" << std::endl;
}

void	Contact::displayFullContact(void)
{
	if (this->index == -1)
		return ;
	std::cout << "First name: " << this->firstName << std::endl;
	std::cout << "Last name: " << this->lastName << std::endl;
	std::cout << "Nickname: " << this->nickname << std::endl;
	std::cout << "Phone number: " << this->phoneNumber << std::endl;
	std::cout << "Darkest secret: " << this->darkestNecret << std::endl;
}

std::string	Contact::truncString(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}
