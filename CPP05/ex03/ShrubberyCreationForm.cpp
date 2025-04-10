#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream> // todo
#include <string>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("Shrubbery Creation Form", 145, 137), _target("No target"){}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("Shrubbery Creation Form", 145, 137), _target(target){}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), _target(other._target){}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other){
	if(this != &other){
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const{
	if(!(this->isSigned()))
		throw FormNotSignedException();
	if(executor.getGrade() > this->getRequiredGradeToExecute())
		throw GradeTooLowException();

	std::string filename = _target + "_shrubbery";
	std::ofstream file(filename.c_str());

	if (!file.is_open()){
		std::cerr << "Error: Could not create a file: " << filename << std::endl;
		return;
	}

	file << "       _-_\n";
	file << "    /~~   ~~\\\n";
	file << " /~~         ~~\\\n";
	file << "{               }\n";
	file << " \\  _-     -_  /\n";
	file << "   ~  \\\\ //  ~\n";
	file << "_- -   | | _- _\n";
	file << "  _ -  | |   -_\n";
	file << "      // \\\\\n";

	file.close();

}
