#include "iter.hpp"
#include <iostream>
#include <string>

class Person {
private:
	std::string _name;
	int _age;
public:
	Person(const std::string name, int age) : _name(name), _age(age){}

	void makeMeOlder(){
		printInfo();
		_age++;
		printInfo();
		std::cout << "-----------------" << std::endl;
	}

	void printInfo() const {
		std::cout << "Hello, my name is " << _name <<
			" and current age is " << _age << "." << std::endl;
	}
};

void age(Person &p){
	p.makeMeOlder();
}

void printPersonInfo(const Person& p) {
	p.printInfo();
}

template <typename T>
void increment(T& num) {
	num += 1;
}

template <typename T>
void printStuff(const T& num) {
	std::cout << num << std::endl;
}

int main(){
	int a[] = {1, 2, 3};
	const int b[] = {10, 11, 12, 42};
	int* c = 0;
	double d[] = {4.4, 5.5, 6.6};
	Person people[] = {Person("Rick", 25), Person("Morty", 30), Person("Summer", 130)};

	std::cout << "Before incrementation: " << std::endl;
	iter(a, 3, printStuff);
	std::cout << "-----------------" << std::endl;
	iter(a, 3, increment);
	std::cout << "After incrementation: " << std::endl;
	iter(a, 3, printStuff);
	std::cout << "-----------------" << std::endl;

	iter(b, 4, printStuff);
	std::cout << "-----------------" << std::endl;

	std::cout << "EMPTY STRING: " << std::endl;
	iter(c, 0, printStuff);
	std::cout << "-----------------" << std::endl;

	std::cout << "Before incrementation: " << std::endl;
	iter(d, 3, printStuff);
	iter(d, 3, increment);
	std::cout << "After incrementation: " << std::endl;
	iter(d, 3, printStuff);
	std::cout << "-----------------" << std::endl;

	std::cout << "Class: \n" << std::endl;
	iter(people, 3, age);

	iter(people, 3, printPersonInfo);

	return 0;
}
