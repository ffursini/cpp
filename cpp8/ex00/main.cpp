/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 22:41:20 by fursini           #+#    #+#             */
/*   Updated: 2024/06/09 22:49:29 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	std::vector<int> vec;

	for (int i = 0; i < 10; i++)
		vec.push_back(i);

	try {
		std::vector<int>::iterator it = easyfind(vec, 5);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Not found" << std::endl;
	}

	try {
		std::vector<int>::iterator it = easyfind(vec, 42);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Not found" << std::endl;
	}
}
