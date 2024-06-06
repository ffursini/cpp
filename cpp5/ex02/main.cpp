/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:24:26 by fursini           #+#    #+#             */
/*   Updated: 2024/06/06 00:36:20 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	try {
		Bureaucrat b1("Francesco", 137);
		Bureaucrat v1("Villain", 150);
		ShrubberyCreationForm f1("shrubbery");
		b1.signForm(f1);
		b1.executeForm(f1);
		v1.executeForm(f1);
	} catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		Bureaucrat b2("Michele", 45);
		Bureaucrat v2("Villain", 150);
		RobotomyRequestForm f2("robotomy");
		b2.signForm(f2);
		b2.executeForm(f2);
		b2.executeForm(f2);
		b2.executeForm(f2);
		v2.executeForm(f2);
	} catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		Bureaucrat b3("Edoardo", 5);
		Bureaucrat v3("Villain", 150);
		PresidentialPardonForm f3("presidential");
		b3.signForm(f3);
		b3.executeForm(f3);
		v3.executeForm(f3);
	} catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
