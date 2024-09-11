/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 14:11:16 by mvolkman          #+#    #+#             */
/*   Updated: 2024/09/11 16:01:25 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	_type = "Dog";
	std::cout << "Dog default constructor is called!" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "Dog copy constructor is called!" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog copy assignment operator is called!" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
	}
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor is called!" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "* dog barks *" << std::endl;
}
