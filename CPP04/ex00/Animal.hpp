/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 14:08:55 by mvolkman          #+#    #+#             */
/*   Updated: 2024/09/07 14:18:14 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
protected:
	std::string type;

public:
	Animal() : type("Animal"){}

	virtual ~Animal() {
		std::cout << "Animal destructor called" << std::endl;
	}

	std::string getType() const {
		return type;
	}

	virtual void makeSound() const {
		std::cout << "Animal sound" << std::endl;
	}
};

#endif
