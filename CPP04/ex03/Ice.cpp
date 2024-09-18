/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 13:19:14 by mvolkman          #+#    #+#             */
/*   Updated: 2024/09/18 21:28:06 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>

// Constructor - set the type to "ice"
Ice::Ice() : AMateria("ice") {}

// Copy constructor
Ice::Ice(Ice const & other) : AMateria(other) {}

// Assignment operator
Ice & Ice::operator=(Ice const & other) {
	if (this != &other) {
		AMateria::operator=(other);
	}
	return *this;
}

// Destructor
Ice::~Ice() {}

// Clone function - return a new instance of Ice
AMateria* Ice::clone() const {
	return new Ice(*this);
}

// Use function - print the required message
void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
