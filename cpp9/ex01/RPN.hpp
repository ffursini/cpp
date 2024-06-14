/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:21:20 by fursini           #+#    #+#             */
/*   Updated: 2024/06/13 22:11:29 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <sstream>

class RPN
{
	private:
		std::stack<int> stack;

		void validSize(int size);
		void division(int a, int b);
		void pushNumber(std::string token);

	public:
		RPN();
		RPN(const RPN &src);
		RPN &operator=(const RPN &src);
		~RPN();

		void calculate(std::string input);

		class InvalidExpression : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "Error: invalid expression.";
				}
		};

		class DivisionByZero : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "Error: division by zero.";
				}
		};

		class NotANumber : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "Error: not a number.";
				}
		};
};

#endif
