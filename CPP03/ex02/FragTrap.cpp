/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:31:00 by mvolkman          #+#    #+#             */
/*   Updated: 2024/09/07 12:06:01 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " has been created!" << std::endl;
}

//TODO: Do you need to assign values again? Because it works in the base class.
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "FragTrap " << this->_name << " has been copied!" << std::endl;

	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
		std::cout << "FragTrap " << this->_name << " has been assigned!" << std::endl;

		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << _name << " has been destroyed!" << std::endl;
}

void FragTrap::attack(const std::string& target) {
	if (_hitPoints > 0 && _energyPoints > 0) {
		std::cout << "FragTrap " << _name << " viciously attacks " << target << ", dealing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	} else if (_hitPoints <= 0) {
		std::cout << "FragTrap " << _name << " is too damaged to attack!" << std::endl;
	} else {
		std::cout << "FragTrap " << _name << " has no energy to attack!" << std::endl;
	}
}

void FragTrap::highFivesGuys(void) {
	std::cout << "Hey guys, give me high five ✋!" << std::endl;
}
