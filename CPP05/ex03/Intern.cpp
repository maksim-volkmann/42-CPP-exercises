#include "Intern.hpp"
#include <iostream>
#include "AForm.hpp"

Intern::Intern(){}

Intern::~Intern(){}

Intern::Intern(const Intern& other){
	(void)other;
}

Intern& Intern::operator=(const Intern& other){
	(void)other;
	return *this;
}

AForm* makeForm(std::string& formName, std::string& target){

}