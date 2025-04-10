#include "Bureaucrat.hpp"
#include <iostream>
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("No name"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
	: _name(name){
	if(grade < 1){
		throw GradeTooHighException();
	} else if(grade > 150){
		throw GradeTooLowException();
	}
	_grade = grade;
}

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: _name(other._name), _grade(other._grade){}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if(this != &other){
		// _name = other._name;
		_grade = other._grade;
	}
	return *this;
}

const std::string& Bureaucrat::getName() const{
	return _name;
}
int Bureaucrat::getGrade() const{
	return _grade;
}

void Bureaucrat::increment(){
	if(_grade <= 1){
		throw GradeTooHighException();
	}
	_grade--;
}

void Bureaucrat::decrement(){
	if(_grade >= 150){
		throw GradeTooLowException();
	}
	_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept {
	return "\033[31mGRADE IS TOO HIGH!\033[0m";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept {
	return "\033[31mGRADE IS TOO LOW!\033[0m";
}

void Bureaucrat::signForm(AForm& f){
	try{
		f.beSigned(*this);
		std::cout << _name << " signed " << f.getName() << "." << std::endl;
	} catch (const std::exception& e) {
		std::cout << _name << " could not sign " << f.getName()
			<< " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm& form) const{
	try{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << "." << std::endl;
	} catch (const std::exception& e) {
		std::cerr << _name << " could not execute " << form.getName()
			<< " because: " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b){
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return os;
}
