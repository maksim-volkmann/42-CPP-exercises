#include "ScalarConverter.hpp"
#include <math.h>
#include <limits>
#include <iomanip>
#include <iostream>

bool ScalarConverter::isChar(const std::string& literal) {
	return (literal.size() == 3 && literal[0] == '\'' && literal[2] == '\'');
}

bool ScalarConverter::isSpecial(const std::string& literal) {
	return (literal == "nan" || literal == "nanf" ||
		literal == "inf" || literal == "inff" ||
		literal == "+inf" || literal == "+inff" ||
		literal == "-inf" || literal == "-inff");
}


// static void printChar(double d) {
// 	if (isnan(d) || isinf(d) || d < CHAR_MIN || d > CHAR_MAX) {
// 			std::cout << "char: impossible\n";
// 	} else {
// 			char c = static_cast<char>(d);
// 			if (std::isprint(c))
// 					std::cout << "char: '" << c << std::endl;
// 			else
// 					std::cout << "char: Non displayable" << std::endl;
// 	}
// }

// static void printInt(double d) {
// 	if (isnan(d) || isinf(d) || d < INT_MIN || d > INT_MAX) {
// 			std::cout << "int: impossible\n";
// 	} else {
// 			std::cout << "int: " << static_cast<int>(d) << std::endl;
// 	}
// }

// static void printFloat(double d) {
// 		float f = static_cast<float>(d);
// 		std::cout << "float: " << f;
// 		// Check if whole number (no fractional part)
// 		if (f == static_cast<long>(f) && !isinf(f))
// 				std::cout << ".0";
// 		std::cout << "f\n";
// }

// static void printDouble(double d) {
// 		std::cout << "double: " << d;
// 		// Check if whole number (no fractional part)
// 		if (d == static_cast<long>(d) && !isinf(d))
// 				std::cout << ".0";
// 		std::cout << "\n";
// }

void ScalarConverter::handleNumeric(const std::string& literal) {
	char* end;
	double d = std::strtod(literal.c_str(), &end);
	bool isFloat = (*end == 'f' || *end == 'F');

	// Check for invalid characters after the number
	if ((*end && !isFloat) || (isFloat && *(end + 1) != '\0')) {
		std::cout << "Error: Invalid literal format" << std::endl;
		return;
	}

	// Char conversion
	if (isnan(d) || isinf(d) || d < CHAR_MIN || d > CHAR_MAX) {
		std::cout << "char: impossible" << std::endl;
	} else {
		char c = static_cast<char>(d);
		if (std::isprint(c))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}

	// Int conversion
	if (isnan(d) || isinf(d) || d < INT_MIN || d > INT_MAX) {
		std::cout << "int: impossible" << std::endl;
	} else {
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	}

	// Float conversion
	float f = static_cast<float>(d);
	std::cout << "float: " << f;
	if (f == static_cast<long>(f) && !isinf(f))
		std::cout << ".0";
	std::cout << "f" << std::endl;

	// Double conversion
	std::cout << "double: " << d;
	if (d == static_cast<long>(d) && !isinf(d))
		std::cout << ".0";
	std::cout << std::endl;
}


// Add these to ScalarConverter.cpp
void ScalarConverter::handleChar(const std::string& literal) {
	char c = literal[1];
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c)  << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::handleSpecial(const std::string& literal) {
	std::string base = literal;
	if (base.back() == 'f'){
		base = base.substr(0, base.size() - 1);
	}
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << base << "f" << std::endl;
	std::cout << "double: " << base << std::endl;
}


void ScalarConverter::convert(const std::string& literal) {
	if (literal.empty()) {
		std::cerr << "Error: Empty input" << std::endl;
		return;
	}
	if (isChar(literal)) {
			handleChar(literal);
	} else if (isSpecial(literal)) {
			handleSpecial(literal);
	} else {
			handleNumeric(literal);
	}
}