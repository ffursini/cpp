/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 22:51:23 by fursini           #+#    #+#             */
/*   Updated: 2024/05/26 23:42:54 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	std::string name1;
	std::string name2;

	std::cout << "Enter the name of the first ClapTrap: ";
	std::getline(std::cin, name1);
	std::cout << "Enter the name of the second ClapTrap: ";
	std::getline(std::cin, name2);

	ClapTrap clap1(name1);
	ClapTrap clap2(name2);

	clap1.attack(name2);
	clap2.takeDamage(0);
	clap1.attack(name2);
	clap2.takeDamage(0);

	clap1.beRepaired(1);
	clap2.beRepaired(1);

	clap1.takeDamage(11);
	clap2.takeDamage(11);
	clap1.takeDamage(1);
	clap2.takeDamage(1);

	return 0;
}
