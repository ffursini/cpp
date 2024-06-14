/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:21:08 by fursini           #+#    #+#             */
/*   Updated: 2024/06/13 22:11:38 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &src) {*this = src;}

RPN &RPN::operator=(const RPN &src)
{
	stack = src.stack;
	return *this;
}

RPN::~RPN() {}

void RPN::validSize(int size)
{
	if (size == 2 && stack.size() < size)
		throw InvalidExpression();
	else if (size == 1 && stack.size() != size)
		throw InvalidExpression();
}

void RPN::division(int a, int b)
{
	if (a == 0)
		throw DivisionByZero();
	stack.push(b / a);
}

void RPN::pushNumber(std::string token)
{
	std::string::iterator it = token.begin();
	while (it != token.end())
	{
		if (!std::isdigit(*it))
			throw NotANumber();
		it++;
	}
	stack.push(std::stoi(token));
}

void RPN::calculate(std::string input)
{
	std::stringstream ss(input);
	std::string token;
	while (ss >> token)
	{
		try
		{
			if (token == "+" || token == "-" || token == "*" || token == "/")
			{
				validSize(2);
				int a = stack.top();
				stack.pop();
				int b = stack.top();
				stack.pop();
				if (token == "+")
					stack.push(b + a);
				else if (token == "-")
					stack.push(b - a);
				else if (token == "*")
					stack.push(b * a);
				else if (token == "/")
					division(a, b);
			}
			else
				pushNumber(token);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
			exit(1);
		}
	}
	try
	{
		validSize(1);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		exit(1);
	}
	std::cout << stack.top() << std::endl;
}
