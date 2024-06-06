/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 01:02:33 by fursini           #+#    #+#             */
/*   Updated: 2024/06/06 01:34:50 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern& src)
{
	(void)src;
}

Intern& Intern::operator=(const Intern& src)
{
	(void)src;
	return *this;
}

Intern::~Intern()
{
}

AForm* Intern::makeForm(const std::string name, const std::string target)
{
	std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* form;
	int i = 0;

	while (i < 3 && name.compare(forms[i]))
		i++;
	switch (i)
	{
		case 0:
			form = new ShrubberyCreationForm(target);
			break;
		case 1:
			form = new RobotomyRequestForm(target);
			break;
		case 2:
			form = new PresidentialPardonForm(target);
			break;
		default:
			std::cout << "Form not found" << std::endl;
			return NULL;
	}
	std::cout << "Intern creates " << form->getName() << std::endl;
	return form;
}
