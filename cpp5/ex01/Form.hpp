/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:03:21 by fursini           #+#    #+#             */
/*   Updated: 2024/06/05 20:27:11 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string name;
		bool isSigned;
		const int gradeToSign;
		const int gradeToExecute;
	public:
		Form(const std::string name, int gradeToSign, int gradeToExecute);
		Form(const Form& src);
		Form& operator=(const Form& src);
		~Form();

		std::string getName() const;
		bool getIsSigned() const;
		int	getGradeToSign() const;
		int	getGradeToExecute() const;

		void beSigned(const Bureaucrat& src);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Grade is too high";
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Grade is too low";
				}
		};
};

std::ostream& operator<<(std::ostream& os, Form const& src);

#endif
