/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 22:45:25 by fursini           #+#    #+#             */
/*   Updated: 2024/05/26 22:45:25 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					fixedPointValue;
		static const int	fractionalBits = 8;
	public:
		Fixed();
		Fixed(const Fixed &src);
		~Fixed();
		Fixed	&operator=(const Fixed &rhs);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
