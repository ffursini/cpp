/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 02:31:29 by fursini           #+#    #+#             */
/*   Updated: 2024/06/06 18:02:08 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& src) {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& src) {return *this;}

ScalarConverter::~ScalarConverter() {}

std::string ScalarConverter::input;
int ScalarConverter::type;
char ScalarConverter::c;
int ScalarConverter::i;
float ScalarConverter::f;
double ScalarConverter::d;


bool ScalarConverter::isChar()
{
	if (input.length() == 1 && !isdigit(input[0]))
		return true;
	return false;
}

bool ScalarConverter::isInt()
{
	if (input.length() == 1 && isdigit(input[0]))
		return true;
	if (input.length() > 1 && (input.length() < 11 || (input.length() == 11 && (input[0] == '-' || input[0] == '+'))) && (isdigit(input[0]) || input[0] == '-' || input[0] == '+'))
	{
		for (size_t i = 1; i < input.length(); i++)
		{
			if (!isdigit(input[i]))
				return false;
		}
		long long tmp = std::stoll(input);
		if (tmp >= INT_MIN && tmp <= INT_MAX)
			return true;
	}
	return false;
}

bool ScalarConverter::isFloat()
{
	if (input.length() == 1 && isdigit(input[0]))
		return true;
	if (input.length() > 1 && (isdigit(input[0]) || input[0] == '-' || input[0] == '+') && input[input.length() - 1] == 'f')
	{
		int dot = 0;
		for (size_t i = 1; i < input.length() - 1; i++)
		{
			if (input[i] == '.')
				dot++;
			else if (!isdigit(input[i]))
				return false;
		}
		if (dot == 1)
			return true;
	}
	return false;
}

bool ScalarConverter::isDouble()
{
	if (input.length() == 1 && isdigit(input[0]))
		return true;
	if (input.length() > 1 && (isdigit(input[0]) || input[0] == '-' || input[0] == '+'))
	{
		int dot = 0;
		for (size_t i = 1; i < input.length(); i++)
		{
			if (input[i] == '.')
				dot++;
			else if (!isdigit(input[i]))
				return false;
		}
		if (dot == 1)
			return true;
	}
	return false;
}

bool ScalarConverter::isPseudoLiteral()
{
	if (input.compare("-inff") == 0 || input.compare("+inff") == 0 || input.compare("-inf") == 0
		|| input.compare("+inf") == 0 || input.compare("nan") == 0 || input.compare("inff") == 0 || input.compare("inf") == 0)
		return true;
	return false;
}

void	ScalarConverter::charToOthers()
{
	c = input[0];
	i = static_cast<int>(c);
	f = static_cast<float>(c);
	d = static_cast<double>(c);
}

void	ScalarConverter::intToOthers()
{
	i = std::stoi(input);
	c = 0;
	if (i >= 32 && i <= 126)
		c = static_cast<char>(i);
	f = static_cast<float>(i);
	d = static_cast<double>(i);
}

void	ScalarConverter::floatToOthers()
{
	f = std::stof(input);
	c = 0;
	if (f >= 32 && f <= 126)
		c = static_cast<char>(f);
	i = static_cast<int>(f);
	d = static_cast<double>(f);

}

void	ScalarConverter::doubleToOthers()
{
	d = std::stod(input);
	c = 0;
	if (d >= 32 && d <= 126)
		c = static_cast<char>(d);
	i = static_cast<int>(d);
	f = static_cast<float>(d);
}

void	ScalarConverter::printChar()
{
	std::cout << "char: ";
	if (c < 32 || c > 126)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << c << "'" << std::endl;
}

void	ScalarConverter::printInt()
{
	std::cout << "int: " << i << std::endl;
}

void	ScalarConverter::printFloat()
{
	std::cout << "float: " << f;
	if (f - static_cast<int>(f) == 0)
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

void	ScalarConverter::printDouble()
{
	std::cout << "double: " << d;
	if (d - static_cast<int>(d) == 0)
		std::cout << ".0";
	std::cout << std::endl;
}

void	ScalarConverter::printNone()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

void	ScalarConverter::printPseudoLiteral()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (input.compare("-inff") == 0 || input.compare("+inff") == 0 || input.compare("inff") == 0)
		std::cout << "float: " << input << std::endl;
	else
		std::cout << "float: " << input << "f" << std::endl;

	if (input.compare("-inff") == 0 || input.compare("+inff") == 0 || input.compare("inff") == 0)
		std::cout << "double: " << input.substr(0, input.length() - 1) << std::endl;
	else
		std::cout << "double: " << input << std::endl;
}

void	ScalarConverter::setType()
{
	if (isChar())
		type = CHAR;
	else if (isInt())
		type = INT;
	else if (isFloat())
		type = FLOAT;
	else if (isDouble())
		type = DOUBLE;
	else if (isPseudoLiteral())
		type = PSEUDO_LITERAL;
}

void	ScalarConverter::setValues(const std::string str)
{
	input = str;
	type = NONE;
	c = 0;
	i = 0;
	f = 0;
	d = 0;

}

void	ScalarConverter::convert(std::string input)
{
	setValues(input);
	setType();
	if (type == CHAR)
		charToOthers();
	else if (type == INT)
		intToOthers();
	else if (type == FLOAT)
		floatToOthers();
	else if (type == DOUBLE)
		doubleToOthers();
	display();
}

void	ScalarConverter::display()
{
	if (type == NONE)
		printNone();
	else if (type == PSEUDO_LITERAL)
		printPseudoLiteral();
	else
	{
		printChar();
		printInt();
		printFloat();
		printDouble();
	}
}
