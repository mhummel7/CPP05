/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:04:30 by mhummel           #+#    #+#             */
/*   Updated: 2025/07/16 12:56:21 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm {
public:
	// Constructor and Destructor
	ShrubberyCreationForm(const std::string& target);
	~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm& other); // Copy constructor
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other); // Copy assignment operator

	// Execute
	void execute(Bureaucrat const& executor) const;

private:
	const std::string target_;
};

#endif // SHRUBBERYCREATIONFORM_HPP
