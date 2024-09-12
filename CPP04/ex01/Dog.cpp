/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 14:11:16 by mvolkman          #+#    #+#             */
/*   Updated: 2024/09/12 12:06:06 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	_brain = new Brain();
	_type = "Dog";
	std::cout << "Dog default constructor is called!" << std::endl;
}

// Dog::Dog(const Dog& other) : Animal(other) {
// 	std::cout << "Dog copy constructor is called!" << std::endl;
// 	_brain = new Brain(*other._brain);
// }

// shahow copy example
Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "Dog copy constructor is called!" << std::endl;
	this->_brain = other._brain;
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog copy assignment operator is called!" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	return *this;
}

Dog::~Dog() {
	delete _brain;
	std::cout << "Dog destructor is called!" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "* dog barks *" << std::endl;
}
