#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm(): _name("NoName"), _isSigned(false), requiredGradeToSign_(150), requiredGradeToExecute_(150){}

AForm::AForm(const std::string& name, int requiredGradeToSign, int requiredGradeToExecute)
	: _name(name), _isSigned(false), requiredGradeToSign_(requiredGradeToSign),
	requiredGradeToExecute_(requiredGradeToExecute){
	if(requiredGradeToSign < 1 || requiredGradeToExecute < 1){
		throw GradeTooHighException();
	} else if (requiredGradeToSign > 150 || requiredGradeToExecute > 150){
		throw GradeTooLowException();
	}
}

AForm::~AForm(){}

AForm::AForm(const AForm& other)
	: _name(other._name), _isSigned(other._isSigned), requiredGradeToSign_(other.requiredGradeToSign_),
	requiredGradeToExecute_(other.requiredGradeToExecute_){

}

AForm& AForm::operator=(const AForm& other){
	if(this != &other){
		//cannot copy anything else, because everything else is const
		_isSigned = other._isSigned;
	}
	return *this;
}

const std::string& AForm::getName() const{
	return _name;
}

bool AForm::isSigned() const{
	return _isSigned;
}

int AForm::getRequiredGradeToSign() const{
	return requiredGradeToSign_;
}

int AForm::getRequiredGradeToExecute() const{
	return requiredGradeToExecute_;
}

void AForm::beSigned(const Bureaucrat& b){
	if(b.getGrade() > requiredGradeToSign_){
		throw GradeTooLowException();
	}
	_isSigned = true;
}

const char* AForm::GradeTooHighException::what() const noexcept {
	return "GRADE IS TOO HIGH!";
}

const char* AForm::GradeTooLowException::what() const noexcept {
	return "GRADE IS TOO LOW!";
}

const char* AForm::FormNotSignedException::what() const noexcept {
	return "FORM IS NOT SIGNED!";
}

std::ostream& operator<<(std::ostream& os, const AForm& AForm){
	os << "AForm: " << AForm.getName()
	<< "\nStatus: " << (AForm.isSigned() ? "SIGNED" : "NOT SIGNED")
	<< "\nSign Grade: " << AForm.getRequiredGradeToSign()
	<< "\nExecute Grade: " << AForm.getRequiredGradeToExecute();

	return os;
}
