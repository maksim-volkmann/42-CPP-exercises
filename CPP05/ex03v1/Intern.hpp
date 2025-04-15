#pragma once

#include <string>
#include <stdexcept>


class AForm;

class Intern{
private:
	typedef AForm* (Intern::*FormCreator)(const std::string&) const;

	struct FormEntry {
		const char* name;
		FormCreator creator;
	};

	static const FormEntry formTable[3];

	AForm* createShrubbery(const std::string& target) const;
	AForm* createRobotomy(const std::string& target) const;
	AForm* createPresidential(const std::string& target) const;

public:
	Intern();
	~Intern();
	Intern(const Intern&);
	Intern& operator=(const Intern&);

	AForm* makeForm(const std::string& formName, const std::string& target);

};



