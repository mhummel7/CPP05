/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:01:18 by mhummel           #+#    #+#             */
/*   Updated: 2025/06/23 11:10:04 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Constructor
Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
	: name_(name), isSigned_(false), gradeToSign_(gradeToSign), gradeToExecute_(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

// Destructor
Form::~Form() {}

// Copy constructor
Form::Form(const Form& other)
	: name_(other.name_), isSigned_(other.isSigned_),
	  gradeToSign_(other.gradeToSign_), gradeToExecute_(other.gradeToExecute_) {}

// Copy assignment operator
Form& Form::operator=(const Form& other) {
	if (this != &other) {
		isSigned_ = other.isSigned_;
		// name_, gradeToSign_, gradeToExecute_ are const, cannot be assigned
	}
	return *this;
}

// Getters
const std::string& Form::getName() const {
	return name_;
}

bool Form::getIsSigned() const {
	return isSigned_;
}

int Form::getGradeToSign() const {
	return gradeToSign_;
}

int Form::getGradeToExecute() const {
	return gradeToExecute_;
}

// Sign form
void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > gradeToSign_)
		throw GradeTooLowException();
	isSigned_ = true;
}

// Overload << operator
std::ostream& operator<<(std::ostream& os, const Form& form) {
	os << "Form " << form.getName() << ", signed: " << (form.getIsSigned() ? "yes" : "no")
	   << ", grade to sign: " << form.getGradeToSign()
	   << ", grade to execute: " << form.getGradeToExecute() << ".";
	return os;
}
