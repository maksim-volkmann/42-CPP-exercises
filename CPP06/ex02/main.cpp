#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <memory>
#include <ctime>

Base* generate() {
	int random = std::rand() % 3;

	switch (random) {
		case 0:
			return new A;
		case 1:
			return new B;
		default:
			return new C;
	}
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "Pointer: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Pointer: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Pointer: C" << std::endl;
	else
		std::cout << "Pointer: This object doesn't belong to A B or C classes." << std::endl;
}

void identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "Reference: A" << std::endl;
		return;
	} catch (...) {}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "Reference: B" << std::endl;
		return;
	} catch (...) {}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "Reference: C" << std::endl;
		return;
	} catch (...) {}
		std::cout << "Reference: This object doesn't belong to A B or C classes." << std::endl;
}

int main() {
	std::srand(time(0));

	Base* obj1 = generate();
	Base* obj2 = generate();
	Base* obj3 = generate();
	Base* obj4 = generate();

	Base baseObj;

	identify(obj1);
	identify(obj2);
	identify(obj3);
	identify(obj4);
	identify(&baseObj);

	std::cout << "----------------" << std::endl;

	identify(*obj1);
	identify(*obj2);
	identify(*obj3);
	identify(*obj4);
	identify(baseObj);

	delete obj1;
	delete obj2;
	delete obj3;
	delete obj4;

	return 0;
}
