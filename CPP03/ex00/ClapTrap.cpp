/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.CPP                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:09:24 by mvolkman          #+#    #+#             */
/*   Updated: 2024/09/06 11:08:27 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap " << this->_name << " has been created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
	: _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage) {
	std::cout << "ClapTrap " << this->_name << " has been copied!" << std::endl;
}
ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	if (this != &other) {
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}

	std::cout << "ClapTrap " << this->_name << " has been assigned!" << std::endl;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << this->_name << " has been destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (this->_hitPoints > 0 && this->_energyPoints > 0) {
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	} else if (this->_hitPoints <= 0) {
		std::cout << "ClapTrap " << this->_name << " is dead and cannot attack!" << std::endl;
	} else {
		std::cout << "ClapTrap " << this->_name << " has no energy to attack!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	this->_hitPoints -= amount;
	if (this->_hitPoints > 0) {
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage! Remaining hit points: " << this->_hitPoints << std::endl;
	} else {
		this->_hitPoints = 0;
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage! " << this->_name << " is dead!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if(this->_hitPoints == 0) {
		std::cout << "ClapTrap " << this->_name << " is dead! It cannot repair itself anymore!" << std::endl;
	} else if (this->_energyPoints == 0) {
		std::cout << "ClapTrap " << this->_name << " has no energy points to repair itself!" << std::endl;
	} else {
		unsigned int repairAmount = amount;

		if (this->_hitPoints + amount > 10) {
			repairAmount = 10 - this->_hitPoints;
		}

		this->_hitPoints += repairAmount;
		this->_energyPoints--;

		std::cout << "ClapTrap " << this->_name << " repairs itself for " << repairAmount << " hit points! Remaining hit points: " << this->_hitPoints << std::endl;
	}

}
