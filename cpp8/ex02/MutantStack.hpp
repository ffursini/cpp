/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 23:31:10 by fursini           #+#    #+#             */
/*   Updated: 2024/06/10 10:14:07 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <deque>

template <typename T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
		MutantStack() : std::stack<T, Container>() {}
		MutantStack(MutantStack const & src) : std::stack<T, Container>(src) {}

		MutantStack & operator=(MutantStack const & rhs)
		{
			if (this != &rhs)
				std::stack<T, Container>::operator=(rhs);
			return *this;
		}
		~MutantStack() {}

		typedef typename std::stack<T, Container>::container_type::iterator iterator;

		iterator begin() { return std::stack<T, Container>::c.begin(); }
		iterator end() { return std::stack<T, Container>::c.end(); }
};

#endif
