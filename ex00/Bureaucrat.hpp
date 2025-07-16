/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:00:16 by mhummel           #+#    #+#             */
/*   Updated: 2025/07/16 12:55:10 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat {
public:
	// Constructor and Destructor
	Bureaucrat(const std::string& name, int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat& other); // Copy constructor
	Bureaucrat& operator=(const Bureaucrat& other); // Copy assignment operator

	// Getters
	const std::string& getName() const;
	int getGrade() const;

	// Member functions
	void incrementGrade();
	void decrementGrade();

	// Exception classes
	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw() { return "Grade is too high!"; }
	};

	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw() { return "Grade is too low!"; }
	};

private:
	const std::string name_;
	int grade_;
};

// Overload << operator
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif // BUREAUCRAT_HPP
