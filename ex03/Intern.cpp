/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:13:32 by mhummel           #+#    #+#             */
/*   Updated: 2025/07/16 12:56:58 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <map>
#include <cctype>

// Constructor
Intern::Intern() {}

// Destructor
Intern::~Intern() {}

// Copy constructor
Intern::Intern(const Intern& other) {
	(void)other; // No attributes to copy
}

// Copy assignment operator
Intern& Intern::operator=(const Intern& other) {
	(void)other; // No attributes to assign
	return *this;
}

// Helper function to convert string to lowercase
static std::string toLower(const std::string& str) {
	std::string lower = str;
	for (std::string::iterator it = lower.begin(); it != lower.end(); ++it)
		*it = std::tolower(static_cast<unsigned char>(*it));
	return lower;
}

// Form creation functions
static AForm* createShrubberyForm(const std::string& target) {
	return new ShrubberyCreationForm(target);
}

static AForm* createRobotomyForm(const std::string& target) {
	return new RobotomyRequestForm(target);
}

static AForm* createPresidentialForm(const std::string& target) {
	return new PresidentialPardonForm(target);
}

// makeForm
AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
	typedef AForm* (*FormCreator)(const std::string&);
	std::map<std::string, FormCreator> formMap;

	// Initialize form map
	formMap["shrubbery creation"] = &createShrubberyForm;
	formMap["robotomy request"] = &createRobotomyForm;
	formMap["presidential pardon"] = &createPresidentialForm;

	// Convert formName to lowercase for case-insensitive comparison
	std::string lowerFormName = toLower(formName);

	// Find the form creator
	std::map<std::string, FormCreator>::iterator it = formMap.find(lowerFormName);
	if (it != formMap.end()) {
		AForm* form = it->second(target);
		std::cout << "Intern creates " << form->getName() << std::endl;
		return form;
	}

	// Unknown form
	std::cerr << "Error: Unknown form name '" << formName << "'" << std::endl;
	return NULL;
}
