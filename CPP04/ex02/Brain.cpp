/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:13:51 by mvolkman          #+#    #+#             */
/*   Updated: 2024/09/12 08:24:57 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	for (int i = 0; i < 100; i++) {
		_ideas[i] = "";
	}
	std::cout << "Brain default constructor is called!" << std::endl;
}

Brain::Brain(const Brain& other) {
	for (int i = 0; i < 100; ++i) {
		_ideas[i] = other._ideas[i];
	}
	std::cout << "Brain copy constructor is called!" << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
	if (this != &other) {
		for (int i = 0; i < 100; ++i) {
			_ideas[i] = other._ideas[i];
		}
	}
	std::cout << "Brain assignment operator is called!" << std::endl;
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain destructor is called!" << std::endl;
}

