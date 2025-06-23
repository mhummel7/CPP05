/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:01:22 by mhummel           #+#    #+#             */
/*   Updated: 2025/06/23 11:10:04 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Form {
public:
	// Constructor and Destructor
	Form(const std::string& name, int gradeToSign, int gradeToExecute);
	~Form();
	Form(const Form& other); // Copy constructor
	Form& operator=(const Form& other); // Copy assignment operator

	// Getters
	const std::string& getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	// Member function
	void beSigned(const Bureaucrat& bureaucrat);

	// Exception classes
	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw() { return "Form grade is too high!"; }
	};

	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw() { return "Form grade is too low!"; }
	};

private:
	const std::string name_;
	bool isSigned_;
	const int gradeToSign_;
	const int gradeToExecute_;
};

// Overload << operator
std::ostream& operator<<(std::ostream& os, const Form& form);

#endif // FORM_HPP
