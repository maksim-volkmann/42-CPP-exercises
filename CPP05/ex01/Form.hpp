#pragma once

#include <string>
#include <stdexcept>

class Bureaucrat;

class Form{
private:
	const std::string _name;
	bool _isSigned;
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

