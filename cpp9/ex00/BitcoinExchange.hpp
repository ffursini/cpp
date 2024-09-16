/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:13:50 by fursini           #+#    #+#             */
/*   Updated: 2024/09/16 01:28:01 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <exception>
#include <limits>


class BitcoinExchange
{
	private:
		std::map<std::string, float> database;
		std::string firstDate;

		void isValidLine(std::string line);
		void isPositiveNumber(float value);
		void isTooLargeNumber(float value);
		void isValidDate(std::string date);

		void setFirstDate();
		std::string previousDate(std::string date);
		float getDateValue(std::string date);

		int stringToInt(std::string str);
		bool longerThanMaxInt(std::string str);
		std::string intToString(int value);
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange &operator=(const BitcoinExchange &src);
		~BitcoinExchange();

		void exchange(std::string input);

		class NotPositiveNumber : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "Error: not a positive number.";
				}
		};

		class TooLargeNumber : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "Error: too large number.";
				}
		};

		class BadInput : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "Error: bad input => ";
				}
		};
};

#endif
