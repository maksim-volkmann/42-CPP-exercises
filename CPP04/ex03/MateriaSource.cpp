/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 21:01:36 by mvolkman          #+#    #+#             */
/*   Updated: 2024/09/19 13:38:18 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

// Default Constructor
MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; ++i)
	_learnedMaterias[i] = nullptr;
}

// Copy Constructor
MateriaSource::MateriaSource(MateriaSource const & other) {
	for (int i = 0; i < 4; ++i) {
		if (other._learnedMaterias[i])
			_learnedMaterias[i] = other._learnedMaterias[i]->clone();
		else
			_learnedMaterias[i] = nullptr;
	}
}

// Copy Assignment Operator
MateriaSource & MateriaSource::operator=(MateriaSource const & other) {
	if (this != &other) {
		// Delete existing Materias
		for (int i = 0; i < 4; ++i) {
			if (_learnedMaterias[i]) {
				delete _learnedMaterias[i];
				_learnedMaterias[i] = nullptr;
			}
		}
		// Copy Materias from other
		for (int i = 0; i < 4; ++i) {
			if (other._learnedMaterias[i])
				_learnedMaterias[i] = other._learnedMaterias[i]->clone();
			else
				_learnedMaterias[i] = nullptr;
		}
	}
	return *this;
}

// Destructor
MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; ++i) {
		if (_learnedMaterias[i]) {
			delete _learnedMaterias[i];
			_learnedMaterias[i] = nullptr;
		}
	}
}

void MateriaSource::learnMateria(AMateria* newMateria) {
	if (!newMateria)
		return;
	for (int i = 0; i < 4; ++i) {
		if (!_learnedMaterias[i]) {
			_learnedMaterias[i] = newMateria->clone();
			delete newMateria;
			std::cout << "Materia *" << _learnedMaterias[i]->getType() << "* has been learned." << std::endl;
			return;
		}
	}
	std::cout << "Cannot learn more Materias. The MateriaSource is full." << std::endl;
	delete newMateria;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; ++i) {
		if (_learnedMaterias[i] && _learnedMaterias[i]->getType() == type) {
			return _learnedMaterias[i]->clone();
		}
	}
	return nullptr;
}



