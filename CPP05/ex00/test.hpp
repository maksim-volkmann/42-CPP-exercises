#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>

class Bureaucrat {
private:
    const std::string name; // Constant name
    int grade;              // Grade (1-150)

public:
    // Orthodox Canonical Form
    Bureaucrat(); // Default constructor
    Bureaucrat(const std::string& name, int grade); // Parameterized constructor
    Bureaucrat(const Bureaucrat& other); // Copy constructor
    Bureaucrat& operator=(const Bureaucrat& other); // Copy assignment operator
    ~Bureaucrat(); // Destructor

    // Getters
    const std::string& getName() const;
    int getGrade() const;

	// Grade modification methods
	void incrementGrade();
	void decrementGrade();

    // Exception classes
    class GradeTooHighException : public std::exception {
        const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
        const char* what() const throw();
    };

    // Overload << operator
    friend std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);
};

#endif
