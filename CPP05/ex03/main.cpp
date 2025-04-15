#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
	Intern intern;

	AForm* form1 = intern.makeForm("Shrubbery Creation", "Garden");
	AForm* form2 = intern.makeForm("robotomy request", "Bender");
	AForm* form3 = intern.makeForm("PRESIDENTIAL pardon", "Zaphod");

	AForm* invalid = intern.makeForm("fake form", "Target");

	if (invalid) {
		delete invalid;
	}

	delete form1;
	delete form2;
	delete form3;
}
