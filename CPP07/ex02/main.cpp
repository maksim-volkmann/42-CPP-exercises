#include <iostream>
#include "Array.hpp"

int main() {
	// Test 1: Default constructor
	Array<int> empty;
	std::cout << "Empty size: " << empty.size() << std::endl;

	// Test 2: Parameterized constructor
	Array<int> arr1(5);
	for (unsigned int i = 0; i < arr1.size(); i++) {
		arr1[i] = (i + 1) * 10;
	}

	std::cout << "Parameterized constructor arr1: ";
	for (unsigned int i = 0; i < arr1.size(); i++) {
		std::cout << arr1[i] << " ";
	}
	std::cout << std::endl;

	// Test 3: Copy constructor
	Array<int> copy_arr2(arr1);
	copy_arr2[2] = 42;
	std::cout << "Original[2]: " << arr1[2] << " | " << "Copy_arr2[2]: " << copy_arr2[2] << std::endl;

	// Test 4: Assignment operator
	Array<int> assigned_arr3;
	assigned_arr3 = arr1;
	assigned_arr3[1] = 24;
	std::cout << "Original[1]: " << arr1[1] << " | " << "Assigned[1]: " << assigned_arr3[1] << std::endl;

	// Test 4: Out of bounds
	Array<int> arr4(3);
	try {
		std::cout << "Out of bound check: " << arr4[9] << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "-----------------" << std::endl;

	Array<std::string> strArr1(4);
	strArr1[0] = "Rick";
	strArr1[1] = "and";
	strArr1[2] = "Morty";
	strArr1[3] = "!";
	for (unsigned int i = 0; i < strArr1.size(); i++) {
		std::cout << strArr1[i] << " ";
	}
	std::cout << std::endl;

	strArr1[1] = "kills";

	for (unsigned int i = 0; i < strArr1.size(); i++) {
		std::cout << strArr1[i] << " ";
	}
	std::cout << std::endl;

	// Copy constructor
	Array<std::string> strArr2(strArr1);
	strArr2[1] = "feeds";
	for (unsigned int i = 0; i < strArr2.size(); i++) {
		std::cout << strArr2[i] << " ";
	}
	std::cout << std::endl;

	// Assignment operator
	Array<std::string> strArr3;
	strArr3 = strArr1;
	strArr3[1] = "loves";
	for (unsigned int i = 0; i < strArr3.size(); i++) {
		std::cout << strArr3[i] << " ";
	}
	std::cout << std::endl;

	try {
		std::cout << "Out of bound check: " << strArr3[9] << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "-----------------" << std::endl;

	const Array<std::string> constArr1(strArr3);
	// not letting set values, because its const
	// constArr1[1] = "destroyed";

	for (unsigned int i = 0; i < constArr1.size(); i++) {
		std::cout << constArr1[i] << " ";
	}
	std::cout << std::endl;

	try {
		std::cout << "Out of bound check: " << constArr1[9] << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
