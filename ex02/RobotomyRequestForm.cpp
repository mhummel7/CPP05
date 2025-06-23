/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:05:32 by mhummel           #+#    #+#             */
/*   Updated: 2025/06/23 11:25:49 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

// Constructor
RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", 72, 45), target_(target) {
	std::srand(static_cast<unsigned int>(std::time(NULL)));
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm() {}

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), target_(other.target_) {}

// Copy assignment operator
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		// target_ is const
	}
	return *this;
}

// Execute
void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
	if (!getIsSigned())
		throw NotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();

	std::cout << "*drilling noises* BRRRRRRRR" << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << target_ << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomy of " << target_ << " failed!" << std::endl;
}
