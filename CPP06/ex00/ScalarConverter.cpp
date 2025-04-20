#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <cmath>
#include <iomanip>

ScalarConverter::ScalarConverter(){};
ScalarConverter::~ScalarConverter(){};
ScalarConverter::ScalarConverter(const ScalarConverter &other){
	(void)other;
};
ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other){
	(void)other;
	return *this;
};

// Char detection
bool ScalarConverter::isCharLiteral(const std::string& literal) {
	return literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'';
}

// Special literals detection
bool ScalarConverter::isSpecialLiteral(const std::string& literal) {
	return literal == "nan" || literal == "nanf" ||
			literal == "inf" || literal == "inff" ||
			literal == "+inf" || literal == "+inff" ||
			literal == "-inf" || literal == "-inff";
}

// Char handling
void ScalarConverter::handleChar(const std::string& literal) {
	char c = literal[1];
	int i = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);

	std::cout << "char: '" << c << "'\n";
	std::cout << "int: " << i << "\n";
	std::cout << "float: " << f << ".0f\n";
	std::cout << "double: " << d << ".0\n";
}

// Special values handling
void ScalarConverter::handleSpecial(const std::string& literal) {
	std::string str = literal;
	if (str[str.length() - 1] == 'f')
		str = str.substr(0, str.length() - 1);

	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	std::cout << "float: " << str << "f\n";
	std::cout << "double: " << str << "\n";
}

// Numeric handling
void ScalarConverter::handleNumeric(const std::string& literal) {
	char* end;
	double d = std::strtod(literal.c_str(), &end);
	bool isFloat = (*end == 'f' || *end == 'F');
	std::string remaining(end + (isFloat ? 1 : 0));

	// Check for conversion errors
	if ((*end && !isFloat) || !remaining.empty()) {
		std::cout << "Error: Invalid literal format\n";
		return;
	}

	// Char conversion
	if (std::isnan(d) || std::isinf(d) || d < CHAR_MIN || d > CHAR_MAX) {
		std::cout << "char: impossible\n";
	} else {
		char c = static_cast<char>(d);
		if (std::isprint(c))
			std::cout << "char: '" << c << "'\n";
		else
			std::cout << "char: Non displayable\n";
	}

	// Int conversion
	if (std::isnan(d) || std::isinf(d) || d < INT_MIN || d > INT_MAX) {
		std::cout << "int: impossible\n";
	} else {
		std::cout << "int: " << static_cast<int>(d) << "\n";
	}

	// Float conversion
	float f = static_cast<float>(d);
	std::cout << "float: " << f;
	if (f == static_cast<int>(f) && !std::isinf(f))
		std::cout << ".0";
	std::cout << "f\n";

	// Double conversion
	std::cout << "double: " << d;
	if (d == static_cast<int>(d) && !std::isinf(d))
		std::cout << ".0";
	std::cout << "\n";
}

// Main conversion entry point
void ScalarConverter::convert(const std::string& literal) {
	if (literal.empty()) {
		std::cout << "Error: Empty input\n";
		return;
	}

	if (isCharLiteral(literal)) {
		handleChar(literal);
	} else if (isSpecialLiteral(literal)) {
		handleSpecial(literal);
	} else {
		handleNumeric(literal);
	}
}
