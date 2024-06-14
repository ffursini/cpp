/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 22:37:26 by fursini           #+#    #+#             */
/*   Updated: 2024/06/14 03:40:24 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <chrono>
#include <iomanip>

class PmergeMe
{
	private:
		std::vector<unsigned int> vector;
		std::list<unsigned int> list;
		std::chrono::time_point<std::chrono::system_clock> start;
		std::chrono::time_point<std::chrono::system_clock> end;
		std::chrono::duration<double> time;

		void fillVector(char **av);
		void printVector(std::vector<unsigned int> &vector);
		void sortVector(std::vector<unsigned int> &vector);
		void mergeVector(std::vector<unsigned int> &left, std::vector<unsigned int> &right, std::vector<unsigned int> &vector);

		void fillList(char **av);
		void printList(std::list<unsigned int> &list);
		void sortList(std::list<unsigned int> &list);
		void mergeList(std::list<unsigned int> &left, std::list<unsigned int> &right, std::list<unsigned int> &list);
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &src);
		PmergeMe &operator=(const PmergeMe &src);
		~PmergeMe();

		void execute(char **av);
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
