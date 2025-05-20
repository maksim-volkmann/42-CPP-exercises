#include <iostream>
#include "Span.hpp"
#include <list>

int main()
{
	Span sp = Span(5);

	try {
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
	} catch (const std::exception& e) {
		std::cout << "Exception " << e.what() << std::endl;
	}

	try{
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	} catch (const std::exception& e){
		std::cout << "Exception " << e.what() << std::endl;
	}

	try {
		sp.addNumber(9);
	} catch (const std::exception& e) {
		std::cout << "Exception " << e.what() << std::endl;
	}

	std::cout << "--------------------" << std::endl;

	Span sp1(2);

	try{
		sp1.addNumber(-5);
		sp1.addNumber(10);
	} catch (const std::exception& e){
		std::cout << "Exception " << e.what() << std::endl;
	}

	try{
		std::cout << "Shortest span: " << sp1.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp1.longestSpan() << std::endl;
	} catch (const std::exception& e){
		std::cout << "Exception " << e.what() << std::endl;
	}

	std::cout << "------------------" << std::endl;

	Span sp2(5);

	try{
		sp2.addNumber(-10);
		sp2.addNumber(-5);
		sp2.addNumber(0);
		sp2.addNumber(5);
		sp2.addNumber(10);
	} catch (const std::exception& e){
		std::cout << "Exception " << e.what() << std::endl;
	}

	try{
		std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
	} catch (const std::exception& e){
		std::cout << "Exception " << e.what() << std::endl;
	}

	std::cout << "------------------" << std::endl;

	Span sp10(100000);
	std::vector<int> largeVector;

	try{
		for (int i = 0; i < 100000; ++i) {
			largeVector.push_back(i * 2);
		}
	} catch (const std::exception& e){
		std::cout << "Exception " << e.what() << std::endl;
	}

	try{
		sp10.addNumbers(largeVector.begin(), largeVector.end());
	} catch (const std::exception& e){
		std::cout << "Exception " << e.what() << std::endl;
	}

	try{
		std::cout << "Shortest span: " << sp10.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp10.longestSpan() << std::endl;
	} catch (const std::exception& e){
		std::cout << "Exception " << e.what() << std::endl;
	}

	std::cout << "--------------------" << std::endl;

	Span sp11(5);
	int arr1[] = {2, 3, 4, 5, 100};

	try{
		sp11.addNumbers(arr1, arr1 + 5);
	} catch (const std::exception& e){
		std::cout << "Exception " << e.what() << std::endl;
	}

	try{
		std::cout << "Shortest span: " << sp11.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp11.longestSpan() << std::endl;
	} catch (const std::exception& e){
		std::cout << "Exception " << e.what() << std::endl;
	}

	std::cout << "--------------------" << std::endl;

	Span sp13(4);
	std::list<int> list1 = {100, 1000, 10000, 100000};

	try{
		sp13.addNumbers(list1.begin(), list1.end());
	} catch (const std::exception& e){
		std::cout << "Exception " << e.what() << std::endl;
	}

	try{
		std::cout << "Shortest span: " << sp13.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp13.longestSpan() << std::endl;
	} catch (const std::exception& e){
		std::cout << "Exception " << e.what() << std::endl;
	}

	return 0;
}
