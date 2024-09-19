/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:01:47 by mvolkman          #+#    #+#             */
/*   Updated: 2024/09/19 13:26:24 by mvolkman         ###   ########.fr       */
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
		for (int i = 0; i < _uneqMaterCount; ++i) {
			if (_uneqMater[i]) {
				delete _uneqMater[i];
				_uneqMater[i] = nullptr;
			}
		}
		_uneqMaterCount = 0;

		_name = other._name;

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
	return *this;
}

// Destructor
Character::~Character() {
	for (int i = 0; i < 4; ++i) {
		if (_inventory[i]) {
			delete _inventory[i];
			_inventory[i] = nullptr;
		}
	}
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

void Character::equip(AMateria* m) {
	if (!m)
		return;
	for (int i = 0; i < 4; ++i) {
		if (_inventory[i] == m) {
			std::cout << "This spefic materia is already equipped." << std::endl;
			return;
		}
	}
	for (int i = 0; i < 4; ++i) {
		if (!_inventory[i]) {
			_inventory[i] = m;
			std::cout << "Equipped *" << m->getType() << "* in slot " << i << std::endl;
			return;
		}
	}
	std::cout << "Cannot equip *" << m->getType() << "*. Inventory is full." << std::endl;
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < 4 && _inventory[idx]) {
		if (_uneqMaterCount < 100) {
			_uneqMater[_uneqMaterCount++] = _inventory[idx];
		}
		_inventory[idx] = nullptr;
	}
}

void Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < 4 && _inventory[idx]) {
		_inventory[idx]->use(target);
	} else {
		std::cout << "No Materia in slot " << idx << " to use!" << std::endl;
	}
}
