/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 14:11:01 by mvolkman          #+#    #+#             */
/*   Updated: 2024/09/11 16:27:15 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
	_type = "animal";
	std::cout << "Animal default constructor is called!" << std::endl;
}

Animal::Animal(const Animal& other) : _type(other._type) {
	std::cout << "Animal copy constructor is called!" << std::endl;
}

Animal& Animal::operator=(const Animal& other){
	std::cout << "Animal copy assign operator is called!" << std::endl;
	if (this != &other) {
		this->_type = other._type;
	}
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal destructor is called!" << std::endl;
}

void Animal::makeSound() const {
	std::cout << "* random animal sounds*" << std::endl;
}

std::string Animal::getType() const {
	return _type;
}
