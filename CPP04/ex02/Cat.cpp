/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 14:11:48 by mvolkman          #+#    #+#             */
/*   Updated: 2024/09/17 09:40:57 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	_brain = new Brain();
	_type = "Cat";
	std::cout << "Cat default constructor is called!" << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal(other) {
	std::cout << "Cat copy constructor is called!" << std::endl;
	_brain = new Brain(*other._brain);
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat copy assignment operator is called!" << std::endl;
	if (this != &other) {
		AAnimal::operator=(other);
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	return *this;
}

Cat::~Cat() {
	delete _brain;
	std::cout << "Cat destructor is called!" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "* cat miaus *" << std::endl;
}
