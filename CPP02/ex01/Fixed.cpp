/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 09:40:39 by mvolkman          #+#    #+#             */
/*   Updated: 2024/08/31 16:05:04 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedNumber(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	fixedNumber = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if(this != &other) {
		this->fixedNumber = other.getRawBits();
	}

	return *this;
}

Fixed::Fixed(const int integer) {
	std::cout << "Int constructor called" << std::endl;
	fixedNumber = integer << fractionalBits;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->fixedNumber;
}

void Fixed::setRawBits(int const raw) {
	this->fixedNumber = raw;
}

