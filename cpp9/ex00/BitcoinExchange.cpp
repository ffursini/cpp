/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:13:52 by fursini           #+#    #+#             */
/*   Updated: 2024/09/16 02:02:32 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::ifstream file("data.csv");
	if (!file.is_open())
	{
		std::cerr << "Error: cannot open file." << std::endl;
		exit(1);
	}
	std::string line;
	while (std::getline(file, line))
	{
		if (line == "date,exchange_rate" || line.empty())
			continue;
		std::stringstream ss(line);
		std::string name;
		float value;
		std::getline(ss, name, ',');
		ss >> value;
		database[name] = value;
	}
	file.close();
}


BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	*this = src;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
	database = src.database;
	return *this;
}

void BitcoinExchange::isValidLine(std::string line)
{
	size_t i = 0;

	while (i < line.size())
	{
		if (line[i] == ' ')
		{
			i++;
			break;
		}
		i++;
		if (i == line.size() - 1)
			throw BadInput();
	}

	if (line[i] != '|' || i == 0)
		throw BadInput();
	i++;

	if (i == line.size() - 1 || line[i] != ' ')
		throw BadInput();

}

void BitcoinExchange::isPositiveNumber(float value)
{
	if (value < 0)
		throw NotPositiveNumber();
}

void BitcoinExchange::isTooLargeNumber(float value)
{
	if (value > 1000)
		throw TooLargeNumber();
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::isValidDate(std::string date)
{
	if (date.size() != 10)
		throw BadInput();
	if (date[4] != '-' || date[7] != '-')
		throw BadInput();

	int year = stringToInt(date.substr(0, 4));
	int month = stringToInt(date.substr(5, 2));
	int day = stringToInt(date.substr(8, 2));
	int firstYear = stringToInt(firstDate.substr(0, 4));
	int firstMonth = stringToInt(firstDate.substr(5, 2));
	int firstDay = stringToInt(firstDate.substr(8, 2));

	if (year < firstYear || (year == firstYear && month < firstMonth) || (year == firstYear && month == firstMonth && day < firstDay))
		throw BadInput();

	if (month < 1 || month > 12 || day < 1 || day > 31)
		throw BadInput();

	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		throw BadInput();

	if (month == 2)
	{
		if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
		{
			if (day > 29)
				throw BadInput();
		}
		else if (day > 28)
			throw BadInput();
	}
}

void BitcoinExchange::setFirstDate()
{
	firstDate = database.begin()->first;
}

std::string BitcoinExchange::previousDate(std::string date)
{
	int year = stringToInt(date.substr(0, 4));
	int month = stringToInt(date.substr(5, 2));
	int day = stringToInt(date.substr(8, 2));

	if (day > 1)
		day--;
	else if (month > 1)
	{
		month--;
		if (month == 4 || month == 6 || month == 9 || month == 11)
			day = 30;
		else if (month == 2)
		{
			if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
				day = 29;
			else
				day = 28;
		}
		else
			day = 31;
	}
	else
	{
		year--;
		month = 12;
		day = 31;
	}

	std::string newDate = intToString(year) + "-";
	if (month < 10)
		newDate += "0";
	newDate += intToString(month) + "-";
	if (day < 10)
		newDate += "0";
	newDate += intToString(day);

	return newDate;
}

float BitcoinExchange::getDateValue(std::string date)
{
	if (database.find(date) != database.end())
		return database[date];
	else
	{
		while (database.find(date) == database.end())
			date = previousDate(date);
	}
	return database[date];
}

void BitcoinExchange::exchange(std::string input)
{
	std::ifstream file(input.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: cannot open file." << std::endl;
		exit(1);
	}
	setFirstDate();

	std::string line;
	std::string date;
	float value;

	while (std::getline(file, line))
	{
		if (line.empty() || line == "date | value")
			continue;
		try {
			std::stringstream ss(line);
			std::getline(ss, date, '|');
			date = date.substr(0, 10);
			ss >> value;
			isValidLine(line);
			isValidDate(date);
			isPositiveNumber(value);
			isTooLargeNumber(value);
			std::cout << date << " => " << value << " = " << getDateValue(date) * value << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what();
			if (std::string(e.what()) == "Error: bad input => ")
				std::cerr << date << std::endl;
			else
				std::cerr << std::endl;
		}
	}

	file.close();
}

std::string BitcoinExchange::intToString(int value)
{

	std::string result;
	if (value == 0)
		return "0";
	while (value > 0)
	{
		result = static_cast<char>(value % 10 + '0') + result;
		value /= 10;
	}
	return result;
}

int BitcoinExchange::stringToInt(std::string str)
{
	if (str.empty() || str.size() > 10)
		throw BadInput();

	std::istringstream iss(str);
	long num;

	iss >> num;

	if (iss.fail() || !iss.eof())
		throw BadInput();

	if (num > 2147483647 || num < -2147483648)
		throw BadInput();

	return static_cast<int>(num);
}
