/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:03:24 by fursini           #+#    #+#             */
/*   Updated: 2024/06/05 21:06:14 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& src) : name(src.name), isSigned(src.isSigned), gradeToSign(src.gradeToSign), gradeToExecute(src.gradeToExecute)
{
}

Form& Form::operator=(const Form& src)
{
	if (this == &src)
		return *this;
	isSigned = src.isSigned;
	return *this;
}

Form::~Form()
{
}

std::string Form::getName() const
{
	return name;
}

bool Form::getIsSigned() const
{
	return isSigned;
}

int	Form::getGradeToSign() const
{
	return gradeToSign;
}

int	Form::getGradeToExecute() const
{
	return gradeToExecute;
}

void Form::beSigned(const Bureaucrat& src)
{
	if (src.getGrade() > gradeToSign)
		throw Form::GradeTooLowException();
	isSigned = true;
}

std::ostream& operator<<(std::ostream& os, Form const& src)
{
	os << "Form: " << src.getName() << std::endl
	<< "Grade to sign: " << src.getGradeToSign()<< std::endl
	<< "Grade to execute: " << src.getGradeToExecute() << std::endl
	<< "Is signed: " << src.getIsSigned();
	return os;
}
