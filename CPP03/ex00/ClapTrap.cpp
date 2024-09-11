/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:09:24 by mvolkman          #+#    #+#             */
/*   Updated: 2024/09/11 13:08:45 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name)
	: _name(name),
	  _hitPoints(10),
	  _energyPoints(10),
	  _attackDamage(0) {
	std::cout << "ClapTrap " << this->_name << " has been created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
	: _name(other._name),
	  _hitPoints(other._hitPoints),
	  _energyPoints(other._energyPoints),
	  _attackDamage(other._attackDamage) {
	std::cout << "ClapTrap " << this->_name << " has been copied!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	if (this != &other) {
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
		std::cout << "ClapTrap " << this->_name << " has been assigned!" << std::endl;
	}
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << this->_name << " has been destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (_hitPoints > 0 && _energyPoints > 0) {
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "
			<< _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	} else if (_hitPoints <= 0) {
		std::cout << "ClapTrap " << _name << " is dead and cannot attack!" << std::endl;
	} else {
		std::cout << "ClapTrap " << _name << " has no energy to attack!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " is already dead 💀! Leave him alone!" << std::endl;
		return;
	}
	if (amount > _hitPoints) {
		amount = _hitPoints;
	}
	_hitPoints -= amount;
	std::cout << "ClapTrap " << _name << " takes " << amount
				<< " points of damage! Remaining hit points: " << _hitPoints << std::endl;
	if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " is dead 💀!" << std::endl;
	}
}


void ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " is dead! It cannot repair itself anymore!" << std::endl;
		return;
	}
	if (_energyPoints == 0) {
		std::cout << "ClapTrap " << _name << " has no energy points to repair itself!" << std::endl;
		return;
	}
	if (amount > _energyPoints) {
		std::cout << "ClapTrap " << _name << " cannot repair " << amount
					<< " hit points! Not enough energy points available." << std::endl;
		return;
	}
	_hitPoints += amount;
	_energyPoints -= amount;
	std::cout << "ClapTrap " << _name << " repairs itself for " << amount
				<< " hit points! Remaining hit points: " << _hitPoints
				<< ", remaining energy points: " << _energyPoints << std::endl;
}

