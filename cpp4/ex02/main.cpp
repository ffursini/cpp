/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:08:52 by fursini           #+#    #+#             */
/*   Updated: 2024/05/28 13:13:36 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "---- Creating and Copying Dog ----" << std::endl;
	Dog dog;

	Dog tmp = dog;

	int N = 5;
	const AAnimal *animals[N];

	std::cout << std::endl << "---- Creating animals ----" << std::endl;
	for (int i = 0; i < N; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout << std::endl << "---- Deleting animals ----" << std::endl;
	for (int i = 0; i < N; i++)
	{
		delete animals[i];
	}

	return 0;
}
