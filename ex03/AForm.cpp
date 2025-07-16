/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:03:35 by mhummel           #+#    #+#             */
/*   Updated: 2025/07/16 12:56:39 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// Constructor
AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
	: name_(name), isSigned_(false), gradeToSign_(gradeToSign), gradeToExecute_(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

// Destructor
AForm::~AForm() {}

// Copy constructor
AForm::AForm(const AForm& other)
	: name_(other.name_), isSigned_(other.isSigned_),
	  gradeToSign_(other.gradeToSign_), gradeToExecute_(other.gradeToExecute_) {}

// Copy assignment operator
AForm& AForm::operator=(const AForm& other) {
	if (this != &other) {
		isSigned_ = other.isSigned_;
		// name_, gradeToSign_, gradeToExecute_ are const
	}
	return *this;
}

// Getters
const std::string& AForm::getName() const {
	return name_;
}

bool AForm::getIsSigned() const {
	return isSigned_;
}

int AForm::getGradeToSign() const {
	return gradeToSign_;
}

int AForm::getGradeToExecute() const {
	return gradeToExecute_;
}

// Sign form
void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > gradeToSign_)
		throw GradeTooLowException();
	isSigned_ = true;
}

// Overload << operator
std::ostream& operator<<(std::ostream& os, const AForm& form) {
	os << "Form " << form.getName() << ", signed: " << (form.getIsSigned() ? "yes" : "no")
	   << ", grade to sign: " << form.getGradeToSign()
	   << ", grade to execute: " << form.getGradeToExecute() << ".";
	return os;
}
