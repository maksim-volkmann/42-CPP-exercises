/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:01:47 by mvolkman          #+#    #+#             */
/*   Updated: 2024/09/18 20:28:50 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// Default Constructor
Character::Character() : _name("Unnamed"), _uneqMaterCount(0) {
	for (int i = 0; i < 4; ++i)
		_inventory[i] = nullptr;
	for (int i = 0; i < 100; ++i)
		_uneqMater[i] = nullptr;
}

// Constructor with name
Character::Character(std::string const & name) : _name(name), _uneqMaterCount(0) {
	for (int i = 0; i < 4; ++i)
		_inventory[i] = nullptr;
	for (int i = 0; i < 100; ++i)
		_uneqMater[i] = nullptr;
}

// Copy Constructor
Character::Character(Character const & other) : _name(other._name), _uneqMaterCount(0) {
	for (int i = 0; i < 4; ++i) {
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = nullptr;
	}
	_uneqMaterCount = other._uneqMaterCount;
	for (int i = 0; i < _uneqMaterCount; ++i) {
		if (other._uneqMater[i])
			_uneqMater[i] = other._uneqMater[i]->clone();
		else
			_uneqMater[i] = nullptr;
	}
}

// Copy Assignment Operator
Character & Character::operator=(Character const & other) {
	if (this != &other) {
		for (int i = 0; i < 4; ++i) {
			if (_inventory[i]) {
				delete _inventory[i];
				_inventory[i] = nullptr;
			}
		}
		// Clean up unequipped Materias
		for (int i = 0; i < _uneqMaterCount; ++i) {
			if (_uneqMater[i]) {
				delete _uneqMater[i];
				_uneqMater[i] = nullptr;
			}
		}
		_uneqMaterCount = 0;

		// Copy name
		_name = other._name;

		// Deep copy of inventory
		for (int i = 0; i < 4; ++i) {
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = nullptr;
		}
		// Copy unequipped Materias
		_uneqMaterCount = other._uneqMaterCount;
		for (int i = 0; i < _uneqMaterCount; ++i) {
			if (other._uneqMater[i])
				_uneqMater[i] = other._uneqMater[i]->clone();
			else
				_uneqMater[i] = nullptr;
		}
	}
	return *this;
}

// Destructor
Character::~Character() {
	// Delete Materias in inventory
	for (int i = 0; i < 4; ++i) {
		if (_inventory[i]) {
			delete _inventory[i];
			_inventory[i] = nullptr;
		}
	}
	// Delete unequipped Materias
	for (int i = 0; i < _uneqMaterCount; ++i) {
		if (_uneqMater[i]) {
			delete _uneqMater[i];
			_uneqMater[i] = nullptr;
		}
	}
}

std::string const & Character::getName() const {
	return _name;
}

// equip
void Character::equip(AMateria* m) {
	if (!m)
		return;
	// Add Materia to the first empty slot
	for (int i = 0; i < 4; ++i) {
		if (!_inventory[i]) {
			_inventory[i] = m;
			return;
		}
	}
    // Inventory full, do nothing
}

// unequip
void Character::unequip(int idx) {
	if (idx >= 0 && idx < 4 && _inventory[idx]) {
		// Add the Materia to the unequipped array
		if (_uneqMaterCount < 100) {
			_uneqMater[_uneqMaterCount++] = _inventory[idx];
		} else {
			// Cannot store more unequipped Materias
			// According to exercise rules, we must not delete the Materia here
			// Potential memory leak if we cannot store it
			// Optionally, you can print a warning
			std::cerr << "Warning: Cannot store more unequipped Materias. Potential memory leak." << std::endl;
		}
		_inventory[idx] = nullptr;
	}
}

// use
void Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < 4 && _inventory[idx]) {
		_inventory[idx]->use(target);
	}
	// If no Materia at idx, do nothing
}