/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 22:57:12 by fursini           #+#    #+#             */
/*   Updated: 2024/06/09 23:14:35 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	Span span(5);

	span.addNumber(5);
	span.addNumber(3);
	span.addNumber(17);
	span.addNumber(9);
	span.addNumber(11);

	std::cout << "--- Test with 5 numbers ---" << std::endl;
	std::cout << span << std::endl;

	std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
	std::cout << "Longest span: " << span.longestSpan() << std::endl;
	std::vector<int> vec;
	for (int i = 0; i < 10000; i++)
		vec.push_back(i + i);

	Span span2(100000);

	span2.addNumber(vec.begin(), vec.end());

	std::cout << "--- Test with 100000 numbers ---" << std::endl;
	std::cout << "Shortest span: " << span2.shortestSpan() << std::endl;
	std::cout << "Longest span: " << span2.longestSpan() << std::endl;
}
