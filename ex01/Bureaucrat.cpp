/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:01:11 by mhummel           #+#    #+#             */
/*   Updated: 2025/07/16 12:55:18 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

// Constructor
Bureaucrat::Bureaucrat(const std::string& name, int grade) : name_(name), grade_(grade) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

// Destructor
Bureaucrat::~Bureaucrat() {}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other) : name_(other.name_), grade_(other.grade_) {}

// Copy assignment operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		grade_ = other.grade_;
		// name_ is const, cannot be assigned
	}
	return *this;
}

// Getters
const std::string& Bureaucrat::getName() const {
	return name_;
}

int Bureaucrat::getGrade() const {
	return grade_;
}

// Increment grade (decrease number, since 1 is highest)
void Bureaucrat::incrementGrade() {
	if (grade_ - 1 < 1)
		throw GradeTooHighException();
	grade_--;
}

// Decrement grade (increase number, since 150 is lowest)
void Bureaucrat::decrementGrade() {
	if (grade_ + 1 > 150)
		throw GradeTooLowException();
	grade_++;
}

// Sign form
void Bureaucrat::signForm(Form& form) {
	try {
		form.beSigned(*this);
		std::cout << name_ << " signed " << form.getName() << std::endl;
	} catch (std::exception& e) {
		std::cout << name_ << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

// Overload << operator
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return os;
}
