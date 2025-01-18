#include "Bureaucrat.hpp"

int main() {
	Bureaucrat p;

	Bureaucrat a("Alice", 200);

	std::cout << a.getName() << std::endl;
	a.getGrade();
}
