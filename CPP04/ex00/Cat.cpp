/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 14:11:48 by mvolkman          #+#    #+#             */
/*   Updated: 2024/09/11 16:01:26 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	_type = "Cat";
	std::cout << "Cat default constructor is called!" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << "Cat copy constructor is called!" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat copy assignment operator is called!" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
	}
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor is called!" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "* cat miaus *" << std::endl;
}
