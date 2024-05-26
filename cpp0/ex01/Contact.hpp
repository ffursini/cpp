/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 22:41:15 by fursini           #+#    #+#             */
/*   Updated: 2024/05/26 22:41:17 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
