#pragma once

#include <string>
#include <exception>
#include <stdexcept>

#define RED(text) "\033[31m" << text << "\033[0m"

class Bureaucrat;

class Form{
private:
	const std::string name_;
	bool isSigned_;
	const int requiredGradeToSign_;
	const int requiredGradeToExecute_;

public:
	Form();
	Form(const std::string& name, int requiredGradeToSign, int requiredGradeToExecute);
	~Form();
	Form(const Form&);
	Form& operator=(const Form&);

	const std::string& getName() const;
	bool isSigned() const;
	int getRequiredGradeToSign() const;
	int getRequiredGradeToExecute() const;

	void beSigned(const Bureaucrat&);

	class GradeTooHighException : public std::exception {
		public: const char* what() const noexcept override;
	};

	class GradeTooLowException : public std::exception {
		public: const char* what() const noexcept override;
	};
};

std::ostream& operator<<(std::ostream& os, const Form& form);

