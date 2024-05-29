/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 22:43:51 by fursini           #+#    #+#             */
/*   Updated: 2024/05/29 22:20:50 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name)
{
	this->weapon = NULL;
}

HumanB::~HumanB()
{
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void	HumanB::attack(void)
{
	if (this->weapon == NULL)
	{
		std::cout << this->name << " has no weapon to attack with" << std::endl;
		return ;
	}
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

