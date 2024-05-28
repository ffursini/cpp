/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:07:24 by fursini           #+#    #+#             */
/*   Updated: 2024/05/28 13:13:11 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
	this->brain = new Brain();
}

Cat::Cat(std::string type) : AAnimal(type)
{
	std::cout << "Cat type constructor called" << std::endl;
	this->brain = new Brain();
}

Cat::Cat(const Cat& src) : AAnimal(src)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = src;

}

Cat& Cat::operator=(const Cat& src)
{
	std::cout << "Cat assignation operator called" << std::endl;
	if (this != &src)
	{
		this->type = src.type;
		this->brain = new Brain(*src.brain);
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->brain;
}

void Cat::makeSound() const
{
	std::cout << "Meow Meow" << std::endl;
}
