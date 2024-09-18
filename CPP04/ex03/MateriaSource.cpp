/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 21:01:36 by mvolkman          #+#    #+#             */
/*   Updated: 2024/09/18 21:02:32 by mvolkman         ###   ########.fr       */
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

void MateriaSource::learnMateria(AMateria* m) {
    if (!m)
        return;
    // Find the first empty slot
    for (int i = 0; i < 4; ++i) {
        if (!_learnedMaterias[i]) {
            _learnedMaterias[i] = m->clone(); // Store a copy of the Materia
            return;
        }
    }
    // If the array is full, do nothing (could log a message)
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; ++i) {
        if (_learnedMaterias[i] && _learnedMaterias[i]->getType() == type) {
            return _learnedMaterias[i]->clone(); // Return a new Materia
        }
    }
    // If not found, return nullptr
    return nullptr;
}
