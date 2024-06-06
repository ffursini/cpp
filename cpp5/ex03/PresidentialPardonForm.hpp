/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 21:41:22 by fursini           #+#    #+#             */
/*   Updated: 2024/06/05 21:41:36 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string target;
	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& src);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& src);
		virtual ~PresidentialPardonForm();

		void execute(Bureaucrat const& executor) const;
};

#endif
