/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 23:17:58 by fursini           #+#    #+#             */
/*   Updated: 2024/06/09 22:16:36 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
	Array<int> intArray(3);

	for (unsigned int i = 0; i < intArray.getSize(); i++)
		intArray[i] = i;

	Array<int> intArrayCopy(intArray);

	std::cout << "intArray: " << intArray << std::endl;
	std::cout << "intArrayCopy: " << intArrayCopy << std::endl;

	Array<std::string> stringArray(3);

	stringArray[0] = "Hello";
	stringArray[1] = "World";
	stringArray[2] = "!";

	std::cout << "stringArray: " << stringArray << std::endl;
	try {
		stringArray[3] = "Bruh";
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	Array<char> charArray;

	std::cout << "charArray: " << charArray << std::endl;
}
