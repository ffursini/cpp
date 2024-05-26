/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 22:43:03 by fursini           #+#    #+#             */
/*   Updated: 2024/05/26 22:43:04 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Zombie.hpp"

int main(void)
{
	int N = 3;
	Zombie* horde = zombieHorde(N, "Francesco");
	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete[] horde;
}
