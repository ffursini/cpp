#include "PhoneBook.hpp"

int main()
{
	PhoneBook phoneBook;
	std::string command;

	while (command.compare("EXIT") != 0)
	{
		std::cout << "Enter command: ";
		std::getline(std::cin, command);
		if (command.compare("ADD") == 0)
			phoneBook.addContact();
		else if (command.compare("SEARCH") == 0)
			phoneBook.searchContact();
	}
	return (0);
}
