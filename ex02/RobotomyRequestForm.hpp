/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:05:10 by mhummel           #+#    #+#             */
/*   Updated: 2025/06/23 11:25:50 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm {
public:
	// Constructor and Destructor
	RobotomyRequestForm(const std::string& target);
	~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& other); // Copy constructor
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other); // Copy assignment operator

	// Execute
	void execute(Bureaucrat const& executor) const;

private:
	const std::string target_;
};

#endif // ROBOTOMYREQUESTFORM_HPP
