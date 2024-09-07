/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 09:40:39 by mvolkman          #+#    #+#             */
/*   Updated: 2024/09/07 12:22:58 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedNumber(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int integer) : _fixedNumber(integer << fractionalBits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float number) : _fixedNumber(roundf(number * (1 << fractionalBits))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_fixedNumber = other.getRawBits();
	}
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	return this->_fixedNumber;
}

void Fixed::setRawBits(int const raw) {
	this->_fixedNumber = raw;
}

float Fixed::toFloat(void) const {
	return static_cast<float>(this->_fixedNumber) / (1 << fractionalBits);
}

int Fixed::toInt(void) const {
	return this->_fixedNumber >> fractionalBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}
