/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 21:22:31 by fursini           #+#    #+#             */
/*   Updated: 2024/06/05 21:56:02 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : AForm(src), target(src.target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	if (this == &src)
		return *this;
	AForm::operator=(src);
	target = src.target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	if (this->getIsSigned() == false)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::ofstream file(target + "_shrubbery");
	file << "      /\\      " << "      /\\      " << "      /\\      " << std::endl;
	file << "     /\\*\\     " << "     /\\*\\     " << "     /\\*\\     " << std::endl;
	file << "    /\\O\\*\\    " << "    /\\O\\*\\    " << "    /\\O\\*\\    " << std::endl;
	file << "   /*/\\/\\/\\   " << "   /*/\\/\\/\\   " << "   /*/\\/\\/\\   " << std::endl;
	file << "  /\\O\\/\\*\\/\\  " << "  /\\O\\/\\*\\/\\  " << "  /\\O\\/\\*\\/\\  " << std::endl;
	file << " /\\*\\/\\*\\/\\/\\ " << " /\\*\\/\\*\\/\\/\\ " << " /\\*\\/\\*\\/\\/\\ " << std::endl;
	file << "/\\O\\/\\/*/\\/O/\\" << "/\\O\\/\\/*/\\/O/\\" << "/\\O\\/\\/*/\\/O/\\" << std::endl;
	file << "      ||      " << "      ||      " << "      ||      " << std::endl;
	file << "      ||      " << "      ||      " << "      ||      " << std::endl;
	file << "      ||      " << "      ||      " << "      ||      " << std::endl;
	file.close();
}

