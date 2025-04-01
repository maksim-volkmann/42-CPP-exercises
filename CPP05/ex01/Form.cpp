#include "Form.hpp"
#include <iostream>
#include "Bureaucrat.hpp"

Form::Form(): name_("NoName"), isSigned_(false), requiredGradeToSign_(150), requiredGradeToExecute_(150){}

Form::Form(const std::string& name, int requiredGradeToSign, int requiredGradeToExecute)
	: name_(name), isSigned_(false), requiredGradeToSign_(requiredGradeToSign),
	requiredGradeToExecute_(requiredGradeToExecute){
	if(requiredGradeToSign < 1 || requiredGradeToExecute < 1){
		throw GradeTooHighException();
	} else if (requiredGradeToSign > 150 || requiredGradeToExecute > 150){
		throw GradeTooLowException();
	}
}

Form::~Form(){}

Form::Form(const Form& other)
	: name_(other.name_), isSigned_(other.isSigned_), requiredGradeToSign_(other.requiredGradeToSign_),
	requiredGradeToExecute_(other.requiredGradeToExecute_){

}

Form& Form::operator=(const Form& other){
	if(this != &other){
		//cannot copy anything else, because everything else is const
		isSigned_ = other.isSigned_;
	}
	return *this;
}

const std::string& Form::getName() const{
	return name_;
}

bool Form::isSigned() const{
	return isSigned_;
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
	isSigned_ = true;
}

const char* Form::GradeTooHighException::what() const noexcept {
	return "\033[31mGRADE IS TOO HIGH!\033[0m";
}

const char* Form::GradeTooLowException::what() const noexcept {
	return "\033[31mGRADE IS TOO LOW!\033[0m";
}

std::ostream& operator<<(std::ostream& os, const Form& form){
	os << "Form: " << form.getName()
	<< "\nStatus: " << (form.isSigned() ? "SIGNED" : "NOT SIGNED")
	<< "\nSign Grade: " << form.getRequiredGradeToSign()
	<< "\nExecute Grade: " << form.getRequiredGradeToExecute();

	return os;
}
