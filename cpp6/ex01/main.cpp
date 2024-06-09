/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:07:49 by fursini           #+#    #+#             */
/*   Updated: 2024/06/06 18:21:39 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data data;
	data.s = "I don't want to set the world on fire";
	data.n = 42;

	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "Raw: " << raw << std::endl;
	Data* ptr = Serializer::deserialize(raw);
	std::cout << "Ptr: " << ptr << std::endl;

	std::cout << "Data: " << ptr->s << " " << ptr->n << std::endl;

	return 0;
}
