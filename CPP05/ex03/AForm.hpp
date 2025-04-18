#pragma once

#include <string>
#include <exception>
#include <stdexcept>

#define RED(text) "\033[31m" << text << "\033[0m"

class Bureaucrat;

class AForm{
private:
	const std::string _name;
	bool _isSigned;
	const int requiredGradeToSign_;
	const int requiredGradeToExecute_;

public:
	AForm();
	AForm(const std::string& name, int requiredGradeToSign, int requiredGradeToExecute);
	virtual ~AForm();
	AForm(const AForm&);
	AForm& operator=(const AForm&);

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

	class FormNotSignedException : public std::exception {
		public: const char* what() const noexcept override;
	};

	virtual void execute(const Bureaucrat& executor) const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& AForm);

