/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 22:44:16 by fursini           #+#    #+#             */
/*   Updated: 2024/05/26 22:44:16 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Error: wrong number of arguments" << std::endl;
		return 1;
	}
	Sed	sed(av[1]);
	sed.replaceString(av[2], av[3]);
	return 0;
}
