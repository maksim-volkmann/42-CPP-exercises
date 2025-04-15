#pragma once

#include <string>
#include <stdexcept>

#define RED(text) "\033[31m" << text << "\033[0m"

class AForm;

class Bureaucrat{
private:
	const std::string _name;
	int _grade;

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

	void signForm(AForm&);

	void executeForm(const AForm& form) const;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

