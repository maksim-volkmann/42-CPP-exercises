/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 09:40:39 by mvolkman          #+#    #+#             */
/*   Updated: 2024/09/10 15:09:33 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedNumber(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int integer) : _fixedNumber(integer << _fractionalBits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float number) : _fixedNumber(roundf(number * (1 << _fractionalBits))) {
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
	return _fixedNumber;
}

void Fixed::setRawBits(int const raw) {
	_fixedNumber = raw;
}

float Fixed::toFloat(void) const {
	return static_cast<float>(_fixedNumber) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
	return _fixedNumber >> _fractionalBits;
}

// The 6 comparison operators: >, <, >=, <=, == and !=.
bool Fixed::operator>(const Fixed& other) const {
	return _fixedNumber > other._fixedNumber;
}

bool Fixed::operator<(const Fixed& other) const {
	return _fixedNumber < other._fixedNumber;
}

bool Fixed::operator>=(const Fixed& other) const {
	return _fixedNumber >= other._fixedNumber;
}

bool Fixed::operator<=(const Fixed& other) const {
	return _fixedNumber <= other._fixedNumber;
}

bool Fixed::operator==(const Fixed& other) const {
	return _fixedNumber == other._fixedNumber;
}

bool Fixed::operator!=(const Fixed& other) const {
	return _fixedNumber != other._fixedNumber;
}

// The 4 arithmetic operators: +, -, *, and /.
Fixed Fixed::operator+(const Fixed& other) const {
	return (toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
	return Fixed(toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
	return Fixed(toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
	return Fixed(toFloat() / other.toFloat());
}

//increment & decrement
Fixed& Fixed::operator++() {
	_fixedNumber++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp = *this;
	++(*this);
	return temp;
}

Fixed& Fixed::operator--() {
	_fixedNumber--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp = *this;
	--(*this);
	return temp;
}

//min < max
Fixed& Fixed::min(Fixed& a, Fixed& b) {
	if (a < b) {
		return a;
	} else {
		return b;
	}
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	if (a < b) {
		return a;
	} else {
		return b;
	}
}


Fixed& Fixed::max(Fixed& a, Fixed& b) {
	if (a > b) {
		return a;
	} else {
		return b;
	}
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	if (a > b) {
		return a;
	} else {
		return b;
	}
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}
