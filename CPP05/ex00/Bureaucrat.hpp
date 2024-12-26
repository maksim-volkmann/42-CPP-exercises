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
	Bureaucrat(); // Default constructor
	Bureaucrat(const std::string& name, int grade); // Parameterized constructor
	Bureaucrat(const Bureaucrat& other); // Copy constructor
	Bureaucrat& operator=(const Bureaucrat &other); // Copy assignment operator
	~Bureaucrat(); // Destructor

	// Getters
	const std::string& getName() const;
	int getGrade() const;
};


#endif