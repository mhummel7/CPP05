/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:04:51 by mhummel           #+#    #+#             */
/*   Updated: 2025/07/16 12:57:11 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

// Constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), target_(target) {}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), target_(other.target_) {}

// Copy assignment operator
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		// target_ is const
	}
	return *this;
}

// Execute
void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
	if (!getIsSigned())
		throw NotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();

	std::ofstream ofs((target_ + "_shrubbery").c_str());
	if (!ofs.is_open())
		return; // Silently fail if file cannot be opened
	ofs << "       /\\\n"
		<< "      /  \\\n"
		<< "     /____\\\n"
		<< "       ||   \n"
		<< "       ||   \n"
		<< "    |______|\n";
	ofs.close();
}
