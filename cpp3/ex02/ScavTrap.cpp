/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:22:30 by fursini           #+#    #+#             */
/*   Updated: 2024/05/27 15:14:23 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap " << name << " created!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src.name)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = src;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& src)
{
	this->name = src.name;
	this->hitPoints = src.hitPoints;
	this->energyPoints = src.energyPoints;
	this->attackDamage = src.attackDamage;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " is gone!" << std::endl;
}

void ScavTrap::attack(std::string const& target)
{
	if (this->hitPoints == 0)
	{
		std::cout << "ScavTrap " << name << " is already dead!" << std::endl;
		return ;
	}
	else if (this->energyPoints == 0)
	{
		std::cout << "ScavTrap " << name << " is out of energy!" << std::endl;
		return ;
	}
	this->energyPoints -= 1;
	std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints == 0)
	{
		std::cout << "ScavTrap " << name << " is already dead!" << std::endl;
		return ;
	}
	this->hitPoints -= amount;
	std::cout << "ScavTrap " << name << " takes " << amount << " points of damage!" << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints == 0)
	{
		std::cout << "ScavTrap " << name << " is out of energy!" << std::endl;
		return ;
	}
	this->energyPoints -= 1;
	std::cout << "ScavTrap " << name << " is repaired for " << amount << " points!" << std::endl;
}



void ScavTrap::guardGate()
{
	if (this->hitPoints == 0)
	{
		std::cout << "ScavTrap " << name << " is already dead!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << name << " has entered in Gate keeper mode!" << std::endl;
}
