#include <iostream>
#include <vector>
#include <list>
#include <array>
#include "easyfind.hpp"
#include <deque>

int	main() {
	// vector
	std::vector<int> vector1 = {10, 20, 30, 40, 50};
	try {
		auto it = easyfind(vector1, 30);
		std::cout << "Found: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Not found: " << e.what() << std::endl;
	}
	try {
		auto it = easyfind(vector1, 100);
		std::cout << "Found: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Not found: " << e.what() << std::endl;
	}

	std::cout << "---------------------------" << std::endl;

	// array
	std::array<int, 5> array1 = {1, 2, 3, 4, 5};
	try {
		auto it = easyfind(array1, 1);
		std::cout << "Found: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Not found: " << e.what() << std::endl;
	}
	try {
		auto it = easyfind(array1, 6);
		std::cout << "Found: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Not found: " << e.what() << std::endl;
	}

	std::cout << "---------------------------" << std::endl;

	// Double-ended queue
	std::deque<int> deque1 = {100, 200, 300, 400, 500};
	try {
		auto it = easyfind(deque1, 200);
		std::cout << "Found: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Not found: " << e.what() << std::endl;
	}
	try {
		auto it = easyfind(deque1, 1000);
		std::cout << "Found: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Not found: " << e.what() << std::endl;
	}

	std::cout << "---------------------------" << std::endl;

	// list
	std::list<int> list1 = {11, 12, 13, 15, 16};
	try {
		auto it = easyfind(list1, 13);
		std::cout << "Found: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Not found: " << e.what() << std::endl;
	}
	try {
		auto it = easyfind(list1, 333);
		std::cout << "Found: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Not found: " << e.what() << std::endl;
	}
	return 0;
}
