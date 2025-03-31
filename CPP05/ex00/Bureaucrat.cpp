#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name_("No name"), grade_(150) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
	: name_(name){
	if(grade < 1){
		throw GradeTooHighException();
	} else if(grade > 150){
		throw GradeTooLowException();
	}
	grade_ = grade;
}

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: name_(other.name_), grade_(other.grade_){}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if(this != &other){
		// name_ = other.name_;
		grade_ = other.grade_;
	}
	return *this;
}

const std::string& Bureaucrat::getName() const{
	return name_;
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
	return "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept {
	return "Grade too low!";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b){
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return os;
}
