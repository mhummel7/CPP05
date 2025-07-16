/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:06:26 by mhummel           #+#    #+#             */
/*   Updated: 2025/07/16 12:57:01 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
	Intern intern;

	// Test 1: Create and use ShrubberyCreationForm
	try {
		AForm* form = intern.makeForm("shrubbery creation", "home");
		if (form) {
			Bureaucrat bob("Bob", 130);
			std::cout << *form << std::endl;
			bob.signForm(*form);
			bob.executeForm(*form);
			delete form;
		}
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	// Test 2: Create and use RobotomyRequestForm
	try {
		AForm* form = intern.makeForm("robotomy request", "Bender");
		if (form) {
			Bureaucrat charlie("Charlie", 45);
			std::cout << *form << std::endl;
			charlie.signForm(*form);
			charlie.executeForm(*form);
			delete form;
		}
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	// Test 3: Create and use PresidentialPardonForm
	try {
		AForm* form = intern.makeForm("presidential pardon", "Arthur");
		if (form) {
			Bureaucrat eve("Eve", 5);
			std::cout << *form << std::endl;
			eve.signForm(*form);
			eve.executeForm(*form);
			delete form;
		}
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	// Test 4: Unknown form name
	try {
		AForm* form = intern.makeForm("unknown form", "target");
		if (form) {
			Bureaucrat bob("Bob", 1);
			std::cout << *form << std::endl;
			bob.signForm(*form);
			bob.executeForm(*form);
			delete form;
		}
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}
