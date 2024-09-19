/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 11:18:49 by mvolkman          #+#    #+#             */
/*   Updated: 2024/09/19 13:44:43 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() : _type("unknown"){}

AMateria::AMateria(std::string const & type) : _type(type){}

AMateria::AMateria(AMateria const & other) : _type(other._type) {}

AMateria& AMateria::operator=(AMateria const & other) {
	if (this != &other) {
		this->_type = other._type;
	}
	return *this;
}

AMateria::~AMateria() {}

std::string const &AMateria::getType() const {
	return this->_type;
}

void AMateria::use(ICharacter& target) {
	// This is fallback function, if "Ice" or "Cure" "use" function is not implemented.
	std::cout << "AMateria object use \"use\" function at " << target.getName() << std::endl;
}
