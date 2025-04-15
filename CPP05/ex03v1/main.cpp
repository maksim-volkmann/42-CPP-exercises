#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
	try {
		Bureaucrat Jerry("Jerry", 120);
		std::cout << Jerry << std::endl;
		ShrubberyCreationForm garden("Garden");
		Jerry.signForm(garden);
		Jerry.executeForm(garden);
	} catch (const std::exception& e) {
		std::cerr << "EXCEPTION ERROR: " << e.what() << std::endl;
	}
	std::cout << ".............." << std::endl;

	try {
		Bureaucrat Rick("Rick", 138);
		std::cout << Rick << std::endl;
		ShrubberyCreationForm forest("Forest");
		Rick.signForm(forest);
		Rick.executeForm(forest);
	} catch (const std::exception& e) {
		std::cerr << "EXCEPTION ERROR: " << e.what() << std::endl;
	}
	std::cout << ".............." << std::endl;

	try {
		Bureaucrat Morty("Morty", 30);
		std::cout << Morty << std::endl;
		RobotomyRequestForm robotomy("Bender");

		Morty.signForm(robotomy);
		Morty.executeForm(robotomy);
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << ".............." << std::endl;

	try {
		Bureaucrat Birdperson("Birdperson", 73);
		std::cout << Birdperson << std::endl;
		RobotomyRequestForm robotomy1("Evil Morty");
		Birdperson.signForm(robotomy1);
		Birdperson.executeForm(robotomy1);
	} catch (const std::exception& e) {
		std::cerr << "EXCEPTION ERROR: " << e.what() << std::endl;
	}
	std::cout << ".............." << std::endl;

	try {
		Bureaucrat Summer("Summer", 1);
		std::cout << Summer << std::endl;
		PresidentialPardonForm pardon("Jerry");
		Summer.signForm(pardon);
		Summer.executeForm(pardon);
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}
