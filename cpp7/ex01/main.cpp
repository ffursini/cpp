/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 03:19:44 by fursini           #+#    #+#             */
/*   Updated: 2024/06/08 23:16:10 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
	std::cout << "intArray: ";
	int intArray[] = {0, 1, 2, 3, 4};
	iter(intArray, 5, &print);
	std::cout << std::endl;

	std::cout << "stringArray: ";
	std::string stringArray[] = {"Edoardo", "Kendrick", "42", "Mojang"};
	iter(stringArray, 4, &print);
	std::cout << std::endl;

	std::cout << "doubleArray: ";
	float floatArray[] = {0.0f, 1.1f, 2.2f, 3.3f, 4.4f};
	iter(floatArray, 5, &print);
	std::cout << std::endl;

	std::cout << "charArray: ";
	char charArray[] = {'a', 'b', 'c', 'd', 'e'};
	iter(charArray, 5, &print);
	std::cout << std::endl;

	std::cout << "addOne(charArray): ";
	iter(charArray, 5, &addOne);
	iter(charArray, 5, &print);
	std::cout << std::endl;
	return 0;
}
