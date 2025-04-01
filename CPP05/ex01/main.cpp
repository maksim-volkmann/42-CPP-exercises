#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
	try {
		Bureaucrat Rick("Rick", 100);
		std::cout << Rick << std::endl;
		Form form1("form1", 100, 100);
		std::cout << ".............." << std::endl;
		std::cout << form1 << std::endl;
		std::cout << ".............." << std::endl;
		Rick.signForm(form1);
		std::cout << ".............." << std::endl;
		std::cout << form1 << std::endl;
		std::cout << ".............." << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "EXCEPTION ERROR: " << e.what() << std::endl;
	}

	std::cout << "\n---------------------------\n" << std::endl;

	try {
		Bureaucrat Morty("Morty", 150);
		std::cout << Morty << std::endl;
		Form form2("form2", 1, 1);
		std::cout << ".............." << std::endl;
		std::cout << form2 << std::endl;
		std::cout << ".............." << std::endl;
		Morty.signForm(form2);
		std::cout << ".............." << std::endl;
		std::cout << form2 << std::endl;
		std::cout << ".............." << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "EXCEPTION ERROR: " << e.what() << std::endl;
	}

	std::cout << "\n---------------------------\n" << std::endl;

	try {
		Bureaucrat Summer("Summer", 150);
		std::cout << Summer << std::endl;
		Form form3("form3", 0, 0);
		std::cout << ".............." << std::endl;
		std::cout << form3 << std::endl;
		std::cout << ".............." << std::endl;
		Summer.signForm(form3);
		std::cout << ".............." << std::endl;
		std::cout << form3 << std::endl;
		std::cout << ".............." << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "EXCEPTION ERROR: " << e.what() << std::endl;
	}
}
