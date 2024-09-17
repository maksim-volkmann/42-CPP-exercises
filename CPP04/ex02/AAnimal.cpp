/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 14:11:01 by mvolkman          #+#    #+#             */
/*   Updated: 2024/09/17 11:56:03 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() {
	_type = "animal";
	std::cout << "AAnimal default constructor is called!" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : _type(other._type) {
	std::cout << "AAnimal copy constructor is called!" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other){
	std::cout << "AAnimal copy assign operator is called!" << std::endl;
	if (this != &other) {
		this->_type = other._type;
	}
	return *this;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor is called!" << std::endl;
}

void AAnimal::makeSound() const {
	std::cout << "* random animal sounds*" << std::endl;
}

std::string AAnimal::getType() const {
	return _type;
}
