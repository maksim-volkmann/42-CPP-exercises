#pragma once

#include <string>
#include <exception>
#include <stdexcept> // todo: do i need this?

#define RED(text) "\033[31m" << text << "\033[0m"

class Form;

class Bureaucrat{
private:
	const std::string name_;
	int grade_;

public:
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat&);
	Bureaucrat& operator=(const Bureaucrat&);

	const std::string& getName() const;
	int getGrade() const;

	void increment();
	void decrement();

	class GradeTooHighException : public std::exception {
		public: const char* what() const noexcept override;
	};

	class GradeTooLowException : public std::exception {
		public: const char* what() const noexcept override;
	};

	void signForm(Form&);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

