/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:00:19 by mhummel           #+#    #+#             */
/*   Updated: 2025/07/16 12:55:12 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	// Test 1: Valid bureaucrat
	try {
		Bureaucrat bob("Bob", 42);
		std::cout << bob << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	// Test 2: Grade too high
	try {
		Bureaucrat alice("Alice", 0);
		std::cout << alice << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	// Test 3: Grade too low
	try {
		Bureaucrat charlie("Charlie", 151);
		std::cout << charlie << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	// Test 4: Increment and decrement grade
	try {
		Bureaucrat dave("Dave", 2);
		std::cout << dave << std::endl;
		dave.incrementGrade(); // Should become grade 1
		std::cout << "After increment: " << dave << std::endl;
		dave.incrementGrade(); // Should throw GradeTooHighException
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	// Test 5: Decrement grade
	try {
		Bureaucrat eve("Eve", 149);
		std::cout << eve << std::endl;
		eve.decrementGrade(); // Should become grade 150
		std::cout << "After decrement: " << eve << std::endl;
		eve.decrementGrade(); // Should throw GradeTooLowException
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}
