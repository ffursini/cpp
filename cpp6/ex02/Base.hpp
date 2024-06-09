/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:28:00 by fursini           #+#    #+#             */
/*   Updated: 2024/06/06 18:32:36 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>

class Base
{
	public:
		virtual ~Base() {};
};

class A : public Base {};

class B : public Base {};

class C : public Base {};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif
