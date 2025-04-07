#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
	try {
		Bureaucrat alice("Alice", 137);
		ShrubberyCreationForm garden("Garden");
		alice.signForm(garden);
		alice.executeForm(garden);
	} catch (const std::exception& e) {
		std::cerr << "EXCEPTION ERROR: " << e.what() << std::endl;
	}

	try {
		Bureaucrat bob("Bob", 30);
		RobotomyRequestForm robotomy("Marvin");

		bob.signForm(robotomy);
		bob.executeForm(robotomy);
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try {
		Bureaucrat rick("Rick", 1); // Highest grade
		PresidentialPardonForm pardon("John Doe");

		rick.signForm(pardon);   // Signs successfully (1 ≤ 25)
		rick.executeForm(pardon); // Executes successfully (1 ≤ 5)
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}
