/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 22:57:17 by fursini           #+#    #+#             */
/*   Updated: 2024/06/09 23:09:53 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : n(n) {}

Span::Span(const Span &src) : n(src.n), vector(src.vector) {}

Span &Span::operator=(const Span &src)
{
	if (this != &src)
	{
		n = src.n;
		vector = src.vector;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int n)
{
	if (vector.size() >= this->n)
		throw std::exception();
	vector.push_back(n);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (vector.size() + std::distance(begin, end) > n)
		throw std::exception();
	vector.insert(vector.end(), begin, end);
}

int Span::shortestSpan()
{
	if (vector.size() <= 1)
		throw std::exception();
	std::vector<int> tmp = vector;
	std::sort(tmp.begin(), tmp.end());
	int min = tmp[1] - tmp[0];
	for (size_t i = 1; i < tmp.size(); i++)
	{
		if (tmp[i] - tmp[i - 1] < min)
			min = tmp[i] - tmp[i - 1];
	}
	return min;
}

int Span::longestSpan()
{
	if (vector.size() <= 1)
		throw std::exception();
	std::vector<int> tmp = vector;
	std::sort(tmp.begin(), tmp.end());
	return tmp[tmp.size() - 1] - tmp[0];
}

std::vector<int> Span::getVector() const { return vector; }

std::ostream &operator<<(std::ostream &os, const Span &span)
{
	std::vector<int> vector = span.getVector();
	for (size_t i = 0; i < vector.size(); i++)
		os << vector[i] << " ";
	return os;
}
