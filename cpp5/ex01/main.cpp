/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:24:26 by fursini           #+#    #+#             */
/*   Updated: 2024/06/05 20:49:02 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try {
		Bureaucrat b1("Francesco", 50);
		Form f1("42", 50, 50);
		std::cout << f1 << std::endl;
		b1.signForm(f1);
		std::cout << f1 << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		Bureaucrat b2("Edoardo", 50);
		Form f2("42", 40, 40);
		b2.signForm(f2);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
