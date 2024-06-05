/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:24:26 by fursini           #+#    #+#             */
/*   Updated: 2024/06/05 18:02:03 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat b1("Edoardo", 1);
		std::cout << b1 << std::endl;
		b1.incrementGrade();
	} catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	} try {
		Bureaucrat b2("Francesco", 150);
		std::cout << b2 << std::endl;
		b2.decrementGrade();
	} catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	} try {
		Bureaucrat b3("Michele", 0);
		std::cout << b3 << std::endl;
	} catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	} try {
		Bureaucrat b4("Dario", 151);
		std::cout << b4 << std::endl;
	} catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
}
