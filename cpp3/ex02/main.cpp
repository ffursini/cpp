/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 22:51:23 by fursini           #+#    #+#             */
/*   Updated: 2024/05/27 15:37:59 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	std::string ClapTrapName;
	std::string ScavTrapName;
	std::string FragTrapName;

	std::cout << "Enter name for ClapTrap: ";
	std::cin >> ClapTrapName;
	std::cout << "Enter name for ScavTrap: ";
	std::cin >> ScavTrapName;
	std::cout << "Enter name for FragTrap: ";
	std::cin >> FragTrapName;

	ClapTrap clap(ClapTrapName);
	ScavTrap scav(ScavTrapName);
	FragTrap frag(FragTrapName);

	//ClapTrap tests
	clap.attack(ScavTrapName);
	clap.takeDamage(20);
	clap.beRepaired(20);

	//ScavTrap tests
	scav.attack(FragTrapName);
	scav.takeDamage(20);
	scav.beRepaired(20);
	scav.guardGate();

	//FragTrap tests
	frag.attack(ClapTrapName);
	frag.takeDamage(20);
	frag.beRepaired(20);
	frag.highFivesGuys();

}
