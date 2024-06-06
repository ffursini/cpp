/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:51:47 by fursini           #+#    #+#             */
/*   Updated: 2024/06/06 16:50:43 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: ./convert [literal]" << std::endl;
		return 1;
	}
	ScalarConverter::convertInput(av[1]);
	ScalarConverter::display();
	return 0;
}
