/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 22:41:45 by fursini           #+#    #+#             */
/*   Updated: 2024/05/26 22:41:45 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::addContact(void)
{
	static int i;

	this->contacts[i % 8].setContact(i % 8);
	i++;
}

void	PhoneBook::searchContact(void)
{
	int i = -1;
	std::string index;

	std::cout << "------------------PHONEBOOK------------------" << std::endl;
	while (++i < 8)
		this->contacts[i].displayContact();
	std::cout << "Enter index: ";
	std::cin >> index;
	std::cin.ignore();
	if (index.length() > 1 || index[0] < '0' || index[0] > '7')
	{
		std::cout << "Invalid index" << std::endl;
		return ;
	}
	this->contacts[std::stoi(index)].displayFullContact();
}
