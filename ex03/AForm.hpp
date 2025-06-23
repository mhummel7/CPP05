/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Aform.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:03:17 by mhummel           #+#    #+#             */
/*   Updated: 2025/06/23 11:15:10 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class AForm {
public:
	// Constructor and Destructor
	AForm(const std::string& name, int gradeToSign, int gradeToExecute);
	virtual ~AForm(); // Virtual destructor
	AForm(const AForm& other); // Copy constructor
	AForm& operator=(const AForm& other); // Copy assignment operator

	// Getters
	const std::string& getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	// Member functions
	void beSigned(const Bureaucrat& bureaucrat);
	virtual void execute(Bureaucrat const& executor) const = 0; // Pure virtual

	// Exception classes
	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw() { return "Form grade is too high!"; }
	};

	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw() { return "Form grade is too low!"; }
	};

	class NotSignedException : public std::exception {
	public:
		const char* what() const throw() { return "Form is not signed!"; }
	};

private:
	const std::string name_;
	bool isSigned_;
	const int gradeToSign_;
	const int gradeToExecute_;
};

// Overload << operator
std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif // AFORM_HPP
