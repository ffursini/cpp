/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:17:49 by fursini           #+#    #+#             */
/*   Updated: 2024/05/27 15:23:51 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap " << name << " created!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src.name)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = src;
}

FragTrap& FragTrap::operator=(const FragTrap& src)
{
	name = src.name;
	hitPoints = src.hitPoints;
	energyPoints = src.energyPoints;
	attackDamage = src.attackDamage;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " is gone!" << std::endl;
}

void FragTrap::attack(std::string const& target)
{
	if (hitPoints == 0)
	{
		std::cout << "FragTrap " << name << " is already dead!" << std::endl;
		return ;
	}
	else if (energyPoints == 0)
	{
		std::cout << "FragTrap " << name << " is out of energy!" << std::endl;
		return ;
	}
	energyPoints -= 1;
	std::cout << "FragTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
{
	if (hitPoints == 0)
	{
		std::cout << "FragTrap " << name << " is already dead!" << std::endl;
		return ;
	}
	hitPoints -= amount;
	std::cout << "FragTrap " << name << " takes " << amount << " points of damage!" << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (energyPoints == 0)
	{
		std::cout << "FragTrap " << name << " is out of energy!" << std::endl;
		return ;
	}
	energyPoints -= 1;
	hitPoints += amount;
	std::cout << "FragTrap " << name << " is repaired for " << amount << " points!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	if (hitPoints == 0)
	{
		std::cout << "FragTrap " << name << " is already dead!" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << name << " requests a high five!" << std::endl;
}
