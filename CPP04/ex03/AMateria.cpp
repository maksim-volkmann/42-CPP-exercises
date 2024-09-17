/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 11:18:49 by mvolkman          #+#    #+#             */
/*   Updated: 2024/09/17 14:09:14 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

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
	//TODO: Not sure what is here for now just test print
	std::cout << "AMateria use function to target a target?" << &target << std::endl;
}
