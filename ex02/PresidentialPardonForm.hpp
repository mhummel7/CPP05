/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:05:52 by mhummel           #+#    #+#             */
/*   Updated: 2025/06/23 11:25:49 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm {
public:
	// Constructor and Destructor
	PresidentialPardonForm(const std::string& target);
	~PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm& other); // Copy constructor
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other); // Copy assignment operator

	// Execute
	void execute(Bureaucrat const& executor) const;

private:
	const std::string target_;
};

#endif // PRESIDENTIALPARDONFORM_HPP