/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 22:41:34 by fursini           #+#    #+#             */
/*   Updated: 2024/05/26 22:41:36 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
