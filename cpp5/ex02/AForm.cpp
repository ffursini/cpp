/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:03:24 by fursini           #+#    #+#             */
/*   Updated: 2024/06/05 20:12:54 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const std::string name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& src) : name(src.name), isSigned(src.isSigned), gradeToSign(src.gradeToSign), gradeToExecute(src.gradeToExecute)
{
}

AForm& AForm::operator=(const AForm& src)
{
	if (this == &src)
		return *this;
	isSigned = src.isSigned;
	return *this;
}

AForm::~AForm()
{
}

std::string AForm::getName() const
{
	return name;
}

bool AForm::getIsSigned() const
{
	return isSigned;
}

int	AForm::getGradeToSign() const
{
	return gradeToSign;
}

int	AForm::getGradeToExecute() const
{
	return gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& src)
{
	if (src.getGrade() > gradeToSign)
		throw AForm::GradeTooLowException();
	isSigned = true;
}

std::ostream& operator<<(std::ostream& os, AForm const& src)
{
	os << "Form: " << src.getName() << std::endl
	<< "Grade to sign: " << src.getGradeToSign()<< std::endl
	<< "Grade to execute: " << src.getGradeToExecute() << std::endl
	<< "Is signed: " << src.getIsSigned();
	return os;
}
