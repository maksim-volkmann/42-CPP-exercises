/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 14:04:30 by mvolkman          #+#    #+#             */
/*   Updated: 2024/09/12 12:15:42 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

// int main()
// {
// 	const Animal* meta = new Animal();
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();
// 	std::cout << j->getType() << " " << std::endl;
// 	std::cout << i->getType() << " " << std::endl;
// 	i->makeSound(); //will output the cat sound!
// 	j->makeSound();
// 	meta->makeSound();

// 	delete meta;
// 	delete j;
// 	delete i;

// 	const WrongAnimal* wrongMeta = new WrongAnimal();
// 	const WrongAnimal* wrongCat = new WrongCat();
// 	wrongMeta->makeSound();
// 	wrongCat->makeSound();

// 	delete wrongMeta;
// 	delete wrongCat;
// 	return 0;
// }


// #include "Dog.hpp"
// #include <iostream>

// #include <iostream>

// class Brain {
// public:
//     Brain() {
//         std::cout << "Brain default constructor is called!" << std::endl;
//     }

//     Brain(const Brain&) {
//         std::cout << "Brain copy constructor is called!" << std::endl;
//     }

//     ~Brain() {
//         std::cout << "Brain destructor is called!" << std::endl;
//     }
// };

// class Dog {
// private:
//     Brain* _brain;

// public:
//     Dog() {
//         _brain = new Brain();
//         std::cout << "Dog default constructor is called!" << std::endl;
//     }

//     // Shallow copy constructor
//     Dog(const Dog& other) {
// 		_brain = other._brain;
//         std::cout << "Dog shallow copy constructor is called!" << std::endl;
//     }

// 	// Dog(const Dog& other) {
// 	// 	_brain = new Brain(*other._brain); // Allocate new memory and copy the Brain data
// 	// 	std::cout << "Dog deep copy constructor is called!" << std::endl;
// 	// }


//     ~Dog() {
//         delete _brain;
//         std::cout << "Dog destructor is called!" << std::endl;
//     }
// };

int main() {
    // Dog basic;
	// 	std::cout << "-----------------------------" << std::endl;
    // {
    //     Dog tmp = basic;
	// 	std::cout << "-----------------------------" << std::endl;
    // }

    // // At this point, basic._brain points to memory that has been deleted, leading to undefined behavior.
	// std::cout << "-----------------------------" << std::endl;


	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;



	std::cout << "-----------------------------" << std::endl;

	Dog basic;
	{
		Dog tmp = basic;
		std::cout << "-----------------------------" << std::endl;
	}

	std::cout << "-----------------------------" << std::endl;

	return 0;
}
