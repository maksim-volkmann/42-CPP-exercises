#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <random>
#include <memory>

Base* generate() {
	static std::random_device rd;
	static std::mt19937 gen(rd());
	static std::uniform_int_distribution<> dist(0, 2);

	switch (dist(gen)) {
		case 0: return new A;
		case 1: return new B;
		default: return new C;
	}
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	} catch (...) {}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	} catch (...) {}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	} catch (...) {}
	std::cout << "Unknown" << std::endl;
}

int main() {
	for (int i = 0; i < 5; ++i) {
		Base* obj = generate();
		std::cout << "Pointer type: ";
		identify(obj);
		std::cout << "Reference type: ";
		identify(*obj);
		delete obj;
		std::cout << "----------------" << std::endl;
	}
	return 0;
}
