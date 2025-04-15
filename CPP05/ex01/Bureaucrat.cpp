#include "Bureaucrat.hpp"
#include <iostream>
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("No name"), grade_(150) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
	: _name(name){
	if(grade < 1){
		throw GradeTooHighException();
	} else if(grade > 150){
		throw GradeTooLowException();
	}
	grade_ = grade;
}

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: _name(other._name), grade_(other.grade_){}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if(this != &other){
		// _name = other._name;
		grade_ = other.grade_;
	}
	return *this;
}

const std::string& Bureaucrat::getName() const{
	return _name;
}
int Bureaucrat::getGrade() const{
	return grade_;
}

void Bureaucrat::increment(){
	if(grade_ <= 1){
		throw GradeTooHighException();
	}
	grade_--;
}

void Bureaucrat::decrement(){
	if(grade_ >= 150){
		throw GradeTooLowException();
	}
	grade_++;
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept {
	return "GRADE IS TOO HIGH!";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept {
	return "GRADE IS TOO LOW!";
}

void Bureaucrat::signForm(Form& f){
	try{
		f.beSigned(*this);
		std::cout << _name << " signed " << f.getName() << std::endl;
	} catch (const std::exception& e) {
		std::cout << _name << " couldn't sign " << f.getName()
			<< " because " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b){
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return os;
}
