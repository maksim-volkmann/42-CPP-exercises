#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat {
private:
	const std::string _name;
	int _grade;

public:

	// Default constructor
	Bureaucrat();

	// Parameterized constructor
	Bureaucrat(const std::string& name, int grade);

	//Bureaucrat::GradeTooHighException
	//
	class GradeTooHighException : public std::exception {
	public:
		const char* what() const noexcept override;
	};

	class GradeTooLowException : public std::exception {
	public:
		const char* what() const noexcept override;
	};

	// getters
	const std::string& getName() const;
	int getGrade() const;
};

#endif
