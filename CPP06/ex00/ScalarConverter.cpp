#include "ScalarConverter.hpp"
#include <math.h>
#include <limits>
#include <iomanip>
#include <iostream>
#include <sstream>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }
ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isChar(const std::string& literal) {
	return (literal.size() == 3 && literal[0] == '\'' && literal[2] == '\'');
}

bool ScalarConverter::isSpecial(const std::string& literal) {
	return (literal == "nan" || literal == "nanf" ||
		literal == "inf" || literal == "inff" ||
		literal == "+inf" || literal == "+inff" ||
		literal == "-inf" || literal == "-inff");
}

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

void ScalarConverter::handleNumeric(const std::string& literal) {
	std::string baseStr = literal;
	bool isFloat = false;

	if (!baseStr.empty() && (baseStr.back() == 'f' || baseStr.back() == 'F')) {
		isFloat = true;
		baseStr = baseStr.substr(0, baseStr.size() - 1);
	}

	std::istringstream iss(baseStr);
	double d;
	if (!(iss >> d)) {
		std::cout << "Error: Invalid literal format (invalid double)" << std::endl;
		return;
	}

	char leftover;
	if (iss >> leftover) {
		std::cout << "Error: Invalid literal format (leftover)" << std::endl;
		return;
	}

	if (isnan(d) || isinf(d) || d < CHAR_MIN || d > CHAR_MAX) {
		std::cout << "char: impossible" << std::endl;
	} else {
		char c = static_cast<char>(d);
		if (std::isprint(c))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}

	if (isnan(d) || isinf(d) || d < INT_MIN || d > INT_MAX) {
		std::cout << "int: impossible" << std::endl;
	} else {
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	}

	float f = static_cast<float>(d);
	std::cout << std::setprecision(7) << "float: " << f;
	if (f == static_cast<long>(f) && !isinf(f))
		std::cout << ".0";
	std::cout << "f" << std::endl;

	std::cout << std::setprecision(15) << "double: " << d;
	if (d == static_cast<long>(d) && !isinf(d))
		std::cout << ".0";
	std::cout << std::endl;
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
