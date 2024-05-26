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
