#include "Intern.hpp"
#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cctype>

const Intern::FormEntry Intern::formTable[3] = {
	{"shrubbery creation", &Intern::createShrubbery},
	{"robotomy request", &Intern::createRobotomy},
	{"presidential pardon", &Intern::createPresidential}
};

Intern::Intern(){}

Intern::~Intern(){}

Intern::Intern(const Intern& other){
	(void)other;
}

Intern& Intern::operator=(const Intern& other){
	(void)other;
	return *this;
}

AForm* Intern::createShrubbery(const std::string& target) const {
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string& target) const {
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(const std::string& target) const {
	return new PresidentialPardonForm(target);
}


const char* Intern::FormNameNotFound::what() const noexcept {
	return "FORM WITH THAT NAME DOES NOT EXISTS!";
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
	std::string lowerName;
	for (size_t i = 0; i < formName.length(); ++i) {
		lowerName += std::tolower(formName[i]);
	}

	for (int i = 0; i < 3; ++i) {
		if (lowerName == formTable[i].name) {
			try{
				std::cout << "Intern creates: " << formName << std::endl;
				return (this->*formTable[i].creatorFunction)(target);
			} catch (const std::exception& e){
				std::cerr << "Form creation failed: " << e.what() << std::endl;
				throw;
			}

		}
	}

	throw FormNameNotFound();
}
