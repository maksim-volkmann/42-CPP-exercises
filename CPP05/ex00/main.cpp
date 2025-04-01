#include "Bureaucrat.hpp"
#include <iostream>

int main() {
	try {
		Bureaucrat Rick("Rick", 150);
		std::cout << Rick << std::endl;
		Rick.decrement();
		std::cout << Rick << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "EXCEPTION ERROR: " << e.what() << std::endl;
	}

	std::cout << "--------------" << std::endl;

	try {
		Bureaucrat Morty("Morty", 1);
		std::cout << Morty << std::endl;
		Morty.increment();
		std::cout << Morty << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "EXCEPTION ERROR: " << e.what() << std::endl;
	}

	std::cout << "--------------" << std::endl;

	try {
		Bureaucrat Summer("Summer", 149);
		std::cout << Summer << std::endl;
		Summer.decrement();
		std::cout << Summer << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "EXCEPTION ERROR: " << e.what() << std::endl;
	}

	std::cout << "--------------" << std::endl;

	try {
		Bureaucrat Jerry("Jerry", 149);
		std::cout << Jerry << std::endl;
		Jerry.increment();
		std::cout << Jerry << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "EXCEPTION ERROR: " << e.what() << std::endl;
	}

	std::cout << "--------------" << std::endl;

	try {
		Bureaucrat Homer("Homer", 0);
		std::cout << Homer << std::endl;
		Homer.increment();
		std::cout << Homer << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "EXCEPTION ERROR: " << e.what() << std::endl;
	}

	std::cout << "--------------" << std::endl;

	try {
		Bureaucrat Bart("Bart", 100000);
		std::cout << Bart << std::endl;
		Bart.increment();
		std::cout << Bart << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "EXCEPTION ERROR: " << e.what() << std::endl;
	}
}
