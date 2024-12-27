#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>

class Bureaucrat {
private:
	const std::string name;
	int grade;

public:
	Bureaucrat(); // default constructor
	Bureaucrat(const std::string& name, int grade); // Parameterized constructor
	Bureaucrat(const Bureaucrat& other); // Copy constructor
	Bureaucrat& operator=(const Bureaucrat &other); // Copy assignment operator
	~Bureaucrat(); // Destructor

	//getters
	const std::string& getName() const;
	int getGrade() const;

	void incrementGrade();
	void decrementGrade();

	class GradeTooHighException : public std::exception {
		const char* what() const noexcept override;
	};

	class GradeTooLowException : public std::exception {
		const char* what() const noexcept override;
	};


};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
