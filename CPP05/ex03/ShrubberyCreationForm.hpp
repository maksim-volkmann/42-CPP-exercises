#pragma once

#include <string>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm {
private:
	std::string _target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string& target);
	~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm&);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm&);

	void execute(const Bureaucrat& execute) const;
};
