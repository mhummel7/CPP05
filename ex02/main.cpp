/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:06:26 by mhummel           #+#    #+#             */
/*   Updated: 2025/06/23 11:25:45 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	// Test 1: ShrubberyCreationForm
	try {
		Bureaucrat bob("Bob", 140);
		ShrubberyCreationForm shrub("home");
		std::cout << bob << std::endl << shrub << std::endl;
		bob.signForm(shrub);
		bob.executeForm(shrub); // Should succeed
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	// Test 2: ShrubberyCreationForm, not signed
	try {
		Bureaucrat alice("Alice", 140);
		ShrubberyCreationForm shrub("garden");
		std::cout << alice << std::endl << shrub << std::endl;
		alice.executeForm(shrub); // Should fail (not signed)
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	// Test 3: RobotomyRequestForm
	try {
		Bureaucrat charlie("Charlie", 45);
		RobotomyRequestForm robot("Bender");
		std::cout << charlie << std::endl << robot << std::endl;
		charlie.signForm(robot);
		charlie.executeForm(robot); // 50% success
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	// Test 4: PresidentialPardonForm, grade too low
	try {
		Bureaucrat dave("Dave", 10);
		PresidentialPardonForm pardon("Ford");
		std::cout << dave << std::endl << pardon << std::endl;
		dave.signForm(pardon);
		dave.executeForm(pardon); // Should fail (grade 10 > 5)
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	// Test 5: PresidentialPardonForm, success
	try {
		Bureaucrat eve("Eve", 5);
		PresidentialPardonForm pardon("Arthur");
		std::cout << eve << std::endl << pardon << std::endl;
		eve.signForm(pardon);
		eve.executeForm(pardon); // Should succeed
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}
