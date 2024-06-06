/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 02:31:25 by fursini           #+#    #+#             */
/*   Updated: 2024/06/06 16:54:11 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <climits>
# include <cstdlib>
# include <iomanip>

enum
{
	NONE,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO_LITERAL
};

class ScalarConverter
{
	private:
		static std::string input;
		static int type;
		static char c;
		static int i;
		static float f;
		static double d;

		ScalarConverter();
		ScalarConverter(const ScalarConverter& src);
		ScalarConverter& operator=(const ScalarConverter& src);
		~ScalarConverter();

		static bool isChar();
		static bool isInt();
		static bool isFloat();
		static bool isDouble();
		static bool isPseudoLiteral();

		static void charToOthers();
		static void intToOthers();
		static void floatToOthers();
		static void doubleToOthers();
		static void pseudoLiteralToOthers();

		static void printChar();
		static void printInt();
		static void printFloat();
		static void printDouble();
		static void printPseudoLiteral();
		static void printNone();

		static void setType();
		static void setValues(const std::string str);
	public:
		static	void convertInput(std::string input);
		static	void display();
};


#endif
