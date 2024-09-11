/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 14:12:04 by mvolkman          #+#    #+#             */
/*   Updated: 2024/09/11 16:08:53 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	_type = "WrongAnimal";
	std::cout << "WrongAnimal default constructor is called!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : _type(other._type) {
	std::cout << "WrongAnimal copy constructor is called!" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	std::cout << "WrongAnimal copy assignment operator is called!" << std::endl;
	if (this != &other) {
		this->_type = other._type;
	}
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor is called!" << std::endl;
}

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal makes sound!" << std::endl;
}

std::string WrongAnimal::getType() const {
	return _type;
}
