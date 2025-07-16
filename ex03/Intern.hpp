/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:13:38 by mhummel           #+#    #+#             */
/*   Updated: 2025/07/16 12:57:00 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"

class Intern {
public:
	// Constructor and Destructor
	Intern();
	~Intern();
	Intern(const Intern& other); // Copy constructor
	Intern& operator=(const Intern& other); // Copy assignment operator

	// Member function
	AForm* makeForm(const std::string& formName, const std::string& target);

private:
	// No private attributes needed
};

#endif // INTERN_HPP
