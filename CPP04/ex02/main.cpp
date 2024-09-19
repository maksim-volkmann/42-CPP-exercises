/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 14:04:30 by mvolkman          #+#    #+#             */
/*   Updated: 2024/09/19 14:41:18 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main() {
	std::cout << "1-----------------------------" << std::endl;

	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	std::cout << "2-----------------------------" << std::endl;

	const int numAnimals = 4;
	AAnimal* animalArray[numAnimals];

	for (int i = 0; i < numAnimals / 2; ++i) {
		animalArray[i] = new Dog();
		std::cout << "-" << std::endl;
	}
	for (int i = numAnimals / 2; i < numAnimals; ++i) {
		animalArray[i] = new Cat();
		std::cout << "-" << std::endl;
	}

	for (int i = 0; i < numAnimals; ++i) {
		delete animalArray[i];
		std::cout << "-" << std::endl;
	}

	std::cout << "3-----------------------------" << std::endl;

	Dog basic;
	{
		Dog tmp = basic;
		std::cout << "4-----------------------------" << std::endl;
	}

	std::cout << "5-----------------------------" << std::endl;

	//test here
	// AAnimal* a = new AAnimal();


	return 0;
}
