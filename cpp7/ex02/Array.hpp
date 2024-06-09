/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 23:18:52 by fursini           #+#    #+#             */
/*   Updated: 2024/06/09 22:13:29 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array
{
	private:
		T*	array;
		unsigned int size;
	public:
		Array() : array(NULL), size(0) {};
		Array(unsigned int n) : array(new T[n]()), size(n) {};
		Array(const Array &src) : array(new T[src.size]), size(src.size)
		{
			for (unsigned int i = 0; i < size; i++)
				array[i] = src.array[i];
		}

		Array &operator=(const Array &src)
		{
			if (this != &src)
			{
				delete [] array;
				size = src.size;
				array = new T[size];
				for (unsigned int i = 0; i < size; i++)
					array[i] = src.array[i];
			}
			return *this;
		}
		~Array() { delete [] array; };

		T &operator[](unsigned int i) const
		{
			if (i >= size)
				throw OutOfLimits();
			return array[i];
		}

		unsigned int getSize() const { return size; };

		class OutOfLimits : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "Index out of range";
				}
		};
};

template <typename T>
std::ostream &operator<<(std::ostream &out, const Array<T> &array)
{
	for (unsigned int i = 0; i < array.getSize(); i++)
		out << array[i] << " ";
	return out;
}

#endif
