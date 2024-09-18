/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:02:23 by mvolkman          #+#    #+#             */
/*   Updated: 2024/09/18 21:27:55 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>

// Constructor - set the type to "cure"
Cure::Cure() : AMateria("cure") {}

// Copy constructor
Cure::Cure(Cure const & other) : AMateria(other) {}

// Assignment operator
Cure & Cure::operator=(Cure const & other) {
	if (this != &other) {
		AMateria::operator=(other);
	}
	return *this;
}

// Destructor
Cure::~Cure() {}

// Clone function - return a new instance of Cure
AMateria* Cure::clone() const {
	return new Cure(*this);
}

// Use function - print the required message
void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
