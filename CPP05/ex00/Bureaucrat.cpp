#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("HeWhoShallNotBeNamed"), _grade(150) {
	std::cout << "Default constructor called!" << std::endl;
	// std::cout << "Name: " << _name << std::endl;
	// std::cout << "Grade: " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade) {
	std::cout << "Parameterized constructor caled!" << std::endl;
	// std::cout << "Name: " << _name << std::endl;
	// std::cout << "Grade: " << _grade << std::endl;
}

const std::string& Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}
