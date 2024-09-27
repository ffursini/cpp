/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 22:36:23 by fursini           #+#    #+#             */
/*   Updated: 2024/09/27 15:32:09 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src) {
	*this = src;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src) {
	if (this != &src) {
		this->vector = src.vector;
		this->list = src.list;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::fillVector(char **av) {
	for (int i = 1; av[i]; i++) {
		bool is_digit = true;
		for (size_t j = 0; j < strlen(av[i]); ++j) {
			if (!isdigit(av[i][j])) {
				is_digit = false;
				break;
			}
		}
		if (is_digit)
			this->vector.push_back(atoi(av[i]));
		else
			throw NotANumber();
	}
}

void PmergeMe::printVector(std::vector<unsigned int> &vector) {
	std::vector<unsigned int>::iterator it = vector.begin();
	std::vector<unsigned int>::iterator ite = vector.end();

	// if (vector.size() > 10)
	// 	ite = vector.begin() + 10;
	while (it != ite) {
		std::cout << *it;
		if (it + 1 != ite)
			std::cout << " ";
		it++;
	}
	// if (vector.size() > 10)
	// 	std::cout << " [...]";
	std::cout << std::endl;
}

void PmergeMe::sortVector(std::vector<unsigned int> &vector) {
	int size = vector.size();
	if (size <= 1)
		return;
	int mid = size / 2;
	std::vector<unsigned int> left(vector.begin(), vector.begin() + mid);
	std::vector<unsigned int> right(vector.begin() + mid, vector.end());

	sortVector(left);
	sortVector(right);
	mergeVector(left, right, vector);
}

void PmergeMe::mergeVector(std::vector<unsigned int> &left, std::vector<unsigned int> &right, std::vector<unsigned int> &vector) {
	int leftSize = vector.size() / 2;
	int rightSize = vector.size() - leftSize;
	int i = 0, l = 0, r = 0;

	while (l < leftSize && r < rightSize) {
		if (left[l] < right[r])
			vector[i++] = left[l++];
		else
			vector[i++] = right[r++];
	}
	while (l < leftSize)
		vector[i++] = left[l++];
	while (r < rightSize)
		vector[i++] = right[r++];
}

void PmergeMe::fillList(char **av) {
	for (int i = 1; av[i]; i++) {
		bool is_digit = true;
		for (size_t j = 0; j < strlen(av[i]); ++j) {
			if (!isdigit(av[i][j])) {
				is_digit = false;
				break;
			}
		}
		if (is_digit)
			this->list.push_back(atoi(av[i]));
		else
			throw NotANumber();
	}
}

void PmergeMe::sortList(std::list<unsigned int> &list) {
    int size = list.size();

	if (size <= 1)
        return;

    int mid = size / 2;
    std::list<unsigned int> left;
    std::list<unsigned int> right;

    std::list<unsigned int>::iterator it = list.begin();
    std::advance(it, mid);

    left.insert(left.begin(), list.begin(), it);
    right.insert(right.begin(), it, list.end());

    sortList(left);
    sortList(right);
    mergeList(left, right, list);
}


void PmergeMe::mergeList(std::list<unsigned int> &left, std::list<unsigned int> &right, std::list<unsigned int> &list) {
	std::list<unsigned int>::iterator it = list.begin();
	std::list<unsigned int>::iterator itl = left.begin();
	std::list<unsigned int>::iterator itr = right.begin();

	while (itl != left.end() && itr != right.end()) {
		if (*itl < *itr) {
			*it = *itl;
			itl++;
		} else {
			*it = *itr;
			itr++;
		}
		it++;
	}
	while (itl != left.end()) {
		*it = *itl;
		itl++;
		it++;
	}
	while (itr != right.end()) {
		*it = *itr;
		itr++;
		it++;
	}
}

void PmergeMe::printList(std::list<unsigned int> &list) {
	std::list<unsigned int>::iterator it = list.begin();
	std::list<unsigned int>::iterator ite = list.end();

	// if (list.size() > 10) {
	// 	ite = list.begin();
	// 	std::advance(ite, 10);
	// }
	while (it != ite) {
		std::cout << *it;
		if (++it != ite)
			std::cout << " ";
	}
	// if (list.size() > 10)
	// 	std::cout << " [...]";
	std::cout << std::endl;
}

void PmergeMe::execute(char **av) {
	try {
		fillVector(av);
		fillList(av);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		exit(1);
	}
	// Vector
	std::cout << "Before: ";
	printVector(this->vector);
	start = clock();
	sortVector(this->vector);
	end = clock();
	std::cout << "After: ";
	printVector(this->vector);
	time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << std::fixed << std::setprecision(10) << "Time to process a range of " << this->vector.size() << " elements with std::vector: " << time * 1000 << "ms" << std::endl;

	std::cout << std::endl;

	// List
	std::cout << "Before: ";
	printList(this->list);
	start = clock();
	sortList(this->list);
	end = clock();
	std::cout << "After: ";
	printList(this->list);
	time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << std::fixed << std::setprecision(10) << "Time to process a range of " << this->list.size() << " elements with std::list: " << time * 1000 << "ms" << std::endl;
}
