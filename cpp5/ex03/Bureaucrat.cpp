/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:24:33 by fursini           #+#    #+#             */
/*   Updated: 2024/06/05 21:59:40 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name), grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : name(src.name), grade(src.grade)
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src)
{
	if (this == &src)
		return *this;
	grade = src.grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
}

std::string Bureaucrat::getName() const
{
	return name;
}

int Bureaucrat::getGrade() const
{
	return grade;
}

void Bureaucrat::incrementGrade()
{
	if (grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	grade--;
}

void Bureaucrat::decrementGrade()
{
	if (grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	grade++;
}

void Bureaucrat::signForm(AForm& src)
{
	try {
		src.beSigned(*this);
		std::cout << name << " signed " << src.getName() << std::endl;
	} catch (std::exception& e) {
		std::cout << name << " couldn't sign " << src.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const& form)
{
	try {
		form.execute(*this);
	} catch (std::exception& e) {
		std::cout << name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& src)
{
	os << src.getName() << ", bureaucrat grade " << src.getGrade();
	return os;
}
