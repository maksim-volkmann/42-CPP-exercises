#pragma once

#include <string>
#include <exception>
#include <stdexcept> // todo: do i need this?


class AForm;

class Intern{

public:
	Intern();
	~Intern();
	Intern(const Intern&);
	Intern& operator=(const Intern&);

	AForm* makeForm(std::string& formName, std::string& target);

};



