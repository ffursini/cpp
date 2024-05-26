/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 22:44:28 by fursini           #+#    #+#             */
/*   Updated: 2024/05/26 22:44:28 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

Sed::Sed(std::string filename) : filename(filename)
{
	this->replace = filename + ".replace";
}

Sed::~Sed()
{
}

void	Sed::replaceString(std::string s1, std::string s2)
{
	std::ifstream	ifs(this->filename);
	std::string		line;
	size_t			pos;

	if (!ifs.is_open())
	{
		std::cerr << "Error: could not open file" << std::endl;
		return ;
	}
	std::ofstream	ofs(this->replace);
	while (std::getline(ifs, line))
	{
		while ((pos = line.find(s1)) != std::string::npos)
		{
			line.erase(pos, s1.length());
			line.insert(pos, s2);
		}
		ofs << line << std::endl;
	}
	ifs.close();
	ofs.close();
}
