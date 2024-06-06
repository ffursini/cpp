/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:24:31 by fursini           #+#    #+#             */
/*   Updated: 2024/06/05 21:25:24 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string name;
		int grade;

	public:
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& src);
		Bureaucrat& operator=(const Bureaucrat& src);
		~Bureaucrat();

		std::string getName() const;
		int getGrade() const;

		void incrementGrade();
		void decrementGrade();

		void signForm(AForm& src);

		void executeForm(AForm const& form);

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

std::ostream& operator<<(std::ostream& os, const Bureaucrat& src);

#endif
