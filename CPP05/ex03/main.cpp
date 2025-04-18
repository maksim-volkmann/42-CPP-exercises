#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
	Bureaucrat Rick("Rick", 1);
	std::cout << Rick << std::endl;
	Intern someRandomIntern;

	try {
		AForm* form1 = someRandomIntern.makeForm("robotomy request", "Bender");
		Rick.signForm(*form1);
		Rick.executeForm(*form1);
		delete form1;
	} catch (const std::exception& e) {
		std::cerr << "EXCEPTION ERROR: " << e.what() << std::endl;
	}
	std::cout << ".............." << std::endl;

	try {
		AForm* form2 = someRandomIntern.makeForm("presidential pardon", "Bender");
		Rick.signForm(*form2);
		Rick.executeForm(*form2);
		delete form2;
	} catch (const std::exception& e) {
		std::cerr << "EXCEPTION ERROR: " << e.what() << std::endl;
	}
	std::cout << ".............." << std::endl;

	try {
		AForm* form3 = someRandomIntern.makeForm("shrubbery creation", "Bender");
		Rick.signForm(*form3);
		Rick.executeForm(*form3);
		delete form3;
	} catch (const std::exception& e) {
		std::cerr << "EXCEPTION ERROR: " << e.what() << std::endl;
	}
	std::cout << ".............." << std::endl;

	try {
		AForm* form4 = someRandomIntern.makeForm("kebab creation", "Bender");
		Rick.signForm(*form4);
		Rick.executeForm(*form4);
		delete form4;
	} catch (const std::exception& e) {
		std::cerr << "EXCEPTION ERROR: " << e.what() << std::endl;
	}

	return 0;
}
