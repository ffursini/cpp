/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:24:26 by fursini           #+#    #+#             */
/*   Updated: 2024/06/06 01:53:10 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern	Giorgio;
	AForm*	form[4];

	form[0] = Giorgio.makeForm("shrubbery creation", "Francesco");
	form[1] = Giorgio.makeForm("robotomy request", "Francesco");
	form[2] = Giorgio.makeForm("presidential pardon", "Francesco");
	form[3] = Giorgio.makeForm("Daino", "Edoardo");

	delete form[0];
	delete form[1];
	delete form[2];
	delete form[3];
}
