#include "Bureaucrat.hpp"

// Default Constructor
Bureaucrat::Bureaucrat() : name("Default"), grade(150) {
    // Default name is "Default", grade is set to lowest valid value (150)
}

// Parameterized Constructor
Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade) {
    if (grade < 1) {
        throw GradeTooHighException();
    } else if (grade > 150) {
        throw GradeTooLowException();
    }
}

// Copy Constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {
    // Since 'name' is const, it can only be initialized in the initializer list
}

// Copy Assignment Operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) { // Avoid self-assignment
        // Only 'grade' can be assigned since 'name' is const
        this->grade = other.grade;
    }
    return *this;
}

// Destructor
Bureaucrat::~Bureaucrat() {
    // No dynamic memory to clean up, so nothing special here
}

// Getters
const std::string& Bureaucrat::getName() const {
    return name;
}

int Bureaucrat::getGrade() const {
    return grade;
}

// Increment Grade
void Bureaucrat::incrementGrade() {
    if (grade <= 1) {
        throw GradeTooHighException();
    }
    grade--; // Decrease numeric value (higher rank)
}

// Decrement Grade
void Bureaucrat::decrementGrade() {
    if (grade >= 150) {
        throw GradeTooLowException();
    }
    grade++; // Increase numeric value (lower rank)
}

// Exception: GradeTooHighException
const char* Bureaucrat::GradeTooHighException::what() const noexcept {
    return "Grade is too high!";
}

// Exception: GradeTooLowException
const char* Bureaucrat::GradeTooLowException::what() const noexcept {
    return "Grade is too low!";
}

// Overloaded << Operator
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}
