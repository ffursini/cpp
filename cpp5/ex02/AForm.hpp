/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:03:21 by fursini           #+#    #+#             */
/*   Updated: 2024/06/05 21:37:29 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string name;
		bool isSigned;
		const int gradeToSign;
		const int gradeToExecute;
	public:
		AForm(const std::string name, int gradeToSign, int gradeToExecute);
		AForm(const AForm& src);
		AForm& operator=(const AForm& src);
		virtual ~AForm();

		std::string getName() const;
		bool getIsSigned() const;
		int	getGradeToSign() const;
		int	getGradeToExecute() const;

		void beSigned(const Bureaucrat& src);

		virtual void execute(Bureaucrat const& executor) const = 0;

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

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Form is not signed";
				}
		};
};

std::ostream& operator<<(std::ostream& os, AForm const& src);

#endif
