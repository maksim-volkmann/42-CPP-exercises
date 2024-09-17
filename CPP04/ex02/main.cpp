/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 14:04:30 by mvolkman          #+#    #+#             */
/*   Updated: 2024/09/17 11:26:39 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main() {

	Dog* b = new Dog();
	Cat* c = new Cat();

	b->makeSound();
	c->makeSound();

	delete b;
	delete c;

	// AAnimal* a = new AAnimal();

	// a->makeSound();
	// delete a;



	return 0;
}
