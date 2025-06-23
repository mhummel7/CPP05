/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:01:25 by mhummel           #+#    #+#             */
/*   Updated: 2025/06/23 11:10:05 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	// Test 1: Valid form creation
	try {
		Form f1("Tax Form", 50, 25);
		std::cout << f1 << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	// Test 2: Form with grade too high
	try {
		Form f2("Invalid Form", 0, 25);
		std::cout << f2 << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	// Test 3: Form with grade too low
	try {
		Form f3("Invalid Form", 50, 151);
		std::cout << f3 << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	// Test 4: Bureaucrat signs form successfully
	try {
		Bureaucrat bob("Bob", 40);
		Form f4("Permit", 50, 25);
		std::cout << bob << std::endl << f4 << std::endl;
		bob.signForm(f4);
		std::cout << f4 << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	// Test 5: Bureaucrat grade too low to sign
	try {
		Bureaucrat alice("Alice", 60);
		Form f5("Contract", 50, 25);
		std::cout << alice << std::endl << f5 << std::endl;
		alice.signForm(f5);
		std::cout << f5 << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}
