/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:08:52 by fursini           #+#    #+#             */
/*   Updated: 2024/05/28 11:22:16 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "----- Test 1 -----" << std::endl;

	const Dog* dog = new Dog();
	const Cat* cat = new Cat();

	std::cout << std::endl;
	std::cout << "Dog type: " << dog->getType() << std::endl;
	std::cout << "Cat type: " << cat->getType() << std::endl;
	std::cout << std::endl;
	std::cout << "Dog sound: ";
	dog->makeSound();
	std::cout << "Cat sound: ";
	cat->makeSound();
	std::cout << std::endl;

	delete dog;
	delete cat;

	std::cout << "------------------" << std::endl;
	std::cout << std::endl << "----- Test 2 -----" << std::endl;

	const Animal* animalDog = new Dog();
	const Animal* animalCat = new Cat();
	const Animal* animal = new Animal();

	std::cout << std::endl;
	std::cout << "AnimalDog type: " << animalDog->getType() << std::endl;
	std::cout << "AnimalCat type: " << animalCat->getType() << std::endl;
	std::cout << "Animal type: " << animal->getType() << std::endl;
	std::cout << std::endl;
	std::cout << "AnimalDog sound: ";
	animalDog->makeSound();
	std::cout << "AnimalCat sound: ";
	animalCat->makeSound();
	std::cout << "Animal sound: ";
	animal->makeSound();
	std::cout << std::endl;

	delete animalDog;
	delete animalCat;
	delete animal;

	std::cout << "------------------" << std::endl;
	std::cout << std::endl << "----- Test 3 -----" << std::endl;

	const WrongCat* wrongCat = new WrongCat();
	const WrongAnimal* wrongAnimalWrongCat = new WrongCat();
	const WrongAnimal* wrongAnimal = new WrongAnimal();

	std::cout << std::endl;
	std::cout << "WrongCat type: " << wrongCat->getType() << std::endl;
	std::cout << "WrongAnimalWrongCat type: " << wrongAnimalWrongCat->getType() << std::endl;
	std::cout << "WrongAnimal type: " << wrongAnimal->getType() << std::endl;
	std::cout << std::endl;
	std::cout << "WrongCat sound: ";
	wrongCat->makeSound();
	std::cout << "WrongAnimalWrongCat sound: ";
	wrongAnimalWrongCat->makeSound();
	std::cout << "WrongAnimal sound: ";
	wrongAnimal->makeSound();
	std::cout << std::endl;

	delete wrongCat;
	delete wrongAnimalWrongCat;
	delete wrongAnimal;

	std::cout << "------------------" << std::endl;
	return 0;
}
