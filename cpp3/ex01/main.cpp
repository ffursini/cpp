/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 22:51:23 by fursini           #+#    #+#             */
/*   Updated: 2024/05/27 14:50:42 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	std::string name1;
	std::string name2;

	std::cout << "Enter name for ScavTrap 1: ";
	std::cin >> name1;
	std::cout << "Enter name for ScavTrap 2: ";
	std::cin >> name2;

	ScavTrap scav1(name1);
	ScavTrap scav2(name2);

	scav1.attack(name2);
	scav2.takeDamage(20);
	scav1.guardGate();
	scav2.guardGate();
	scav2.attack(name1);
	scav1.takeDamage(20);
	scav1.beRepaired(20);
	scav2.beRepaired(20);

	return 0;
}
