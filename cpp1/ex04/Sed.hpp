/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 22:44:31 by fursini           #+#    #+#             */
/*   Updated: 2024/05/26 22:44:31 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
#define SED_HPP

#include <iostream>
#include <string>
#include <fstream>

class Sed
{
	private:
		std::string	filename;
		std::string	replace;
	public:
		Sed(std::string filename);
		~Sed();
		void	replaceString(std::string s1, std::string s2);
};

#endif
