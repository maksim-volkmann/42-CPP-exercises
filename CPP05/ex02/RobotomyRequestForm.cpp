#include "RobotomyRequestForm.hpp"
#include <fstream>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("Robotomy Request", 72, 45), _target("No target"){}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("Robotomy Request", 72, 45), _target(target){}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), _target(other._target){}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other){
	if(this != &other){
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const{
	if(!(this->isSigned()))
		throw AForm::FormNotSignedException();
	if(executor.getGrade() > this->getRequiredGradeToExecute())
		throw AForm::GradeTooLowException();

	std::cout << "~~@~~DRILLING NOISES~: BRRRRRRRRRRR~~@~~" << std::endl;

	std::srand(std::time(0));

	if(std::rand() % 2 == 0){
		std::cout << _target << " has been robotomized successfully." << std::endl;
	} else {
		std::cout << _target << " failed to be robotomized." << std::endl;
	}

}
