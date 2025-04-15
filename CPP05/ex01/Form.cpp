#include "Form.hpp"
#include <iostream>
#include "Bureaucrat.hpp"

Form::Form(): _name("NoName"), _isSigned(false), requiredGradeToSign_(150), requiredGradeToExecute_(150){}

Form::Form(const std::string& name, int requiredGradeToSign, int requiredGradeToExecute)
	: _name(name), _isSigned(false), requiredGradeToSign_(requiredGradeToSign),
	requiredGradeToExecute_(requiredGradeToExecute){
	if(requiredGradeToSign < 1 || requiredGradeToExecute < 1){
		throw GradeTooHighException();
	} else if (requiredGradeToSign > 150 || requiredGradeToExecute > 150){
		throw GradeTooLowException();
	}
}

Form::~Form(){}

Form::Form(const Form& other)
	: _name(other._name), _isSigned(other._isSigned), requiredGradeToSign_(other.requiredGradeToSign_),
	requiredGradeToExecute_(other.requiredGradeToExecute_){

}

Form& Form::operator=(const Form& other){
	if(this != &other){
		//cannot copy anything else, because everything else is const
		_isSigned = other._isSigned;
	}
	return *this;
}

const std::string& Form::getName() const{
	return _name;
}

bool Form::isSigned() const{
	return _isSigned;
}

int Form::getRequiredGradeToSign() const{
	return requiredGradeToSign_;
}

int Form::getRequiredGradeToExecute() const{
	return requiredGradeToExecute_;
}

void Form::beSigned(const Bureaucrat& b){
	if(b.getGrade() > requiredGradeToSign_){
		throw GradeTooLowException();
	}
	_isSigned = true;
}

const char* Form::GradeTooHighException::what() const noexcept {
	return "GRADE IS TOO HIGH!";
}

const char* Form::GradeTooLowException::what() const noexcept {
	return "GRADE IS TOO LOW!";
}

std::ostream& operator<<(std::ostream& os, const Form& form){
	os << "Form: " << form.getName()
	<< "\nStatus: " << (form.isSigned() ? "SIGNED" : "NOT SIGNED")
	<< "\nSign Grade: " << form.getRequiredGradeToSign()
	<< "\nExecute Grade: " << form.getRequiredGradeToExecute();

	return os;
}
