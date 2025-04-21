// In ScalarConverter.cpp
#include "ScalarConverter.hpp"
#include <math.h>
#include <limits>
#include <iomanip>
#include <iostream>

static void printChar(double d) {
    if (isnan(d) || isinf(d) || d < CHAR_MIN || d > CHAR_MAX) {
        std::cout << "char: impossible\n";
    } else {
        char c = static_cast<char>(d);
        if (std::isprint(c))
            std::cout << "char: '" << c << "'\n";
        else
            std::cout << "char: Non displayable\n";
    }
}

static void printInt(double d) {
    if (isnan(d) || isinf(d) || d < INT_MIN || d > INT_MAX) {
        std::cout << "int: impossible\n";
    } else {
        std::cout << "int: " << static_cast<int>(d) << "\n";
    }
}

static void printFloat(double d) {
    float f = static_cast<float>(d);
    std::cout << "float: " << f;
    // Check if whole number (no fractional part)
    if (f == static_cast<long>(f) && !isinf(f))
        std::cout << ".0";
    std::cout << "f\n";
}

static void printDouble(double d) {
    std::cout << "double: " << d;
    // Check if whole number (no fractional part)
    if (d == static_cast<long>(d) && !isinf(d))
        std::cout << ".0";
    std::cout << "\n";
}

void ScalarConverter::handleNumeric(const std::string& literal) {
    char* end;
    double d = std::strtod(literal.c_str(), &end);
    bool isFloat = (*end == 'f' || *end == 'F');

    // Check for invalid characters after the number
    if ((*end && !isFloat) || (isFloat && *(end + 1) != '\0')) {
        std::cout << "Error: Invalid literal format\n";
        return;
    }

    printChar(d);
    printInt(d);
    printFloat(d);
    printDouble(d);
}

// Add this to ScalarConverter.cpp
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


// Add these to ScalarConverter.cpp
void ScalarConverter::handleChar(const std::string& literal) {
    char c = literal[1];
    std::cout << "char: '" << c << "'\n";
    std::cout << "int: " << static_cast<int>(c) << "\n";
    std::cout << "float: " << static_cast<float>(c) << ".0f\n";
    std::cout << "double: " << static_cast<double>(c) << ".0\n";
}

void ScalarConverter::handleSpecial(const std::string& literal) {
    std::string base = literal;
    if (base.back() == 'f') base = base.substr(0, base.size() - 1);
    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
    std::cout << "float: " << base << "f\n";
    std::cout << "double: " << base << "\n";
}

bool ScalarConverter::isCharLiteral(const std::string& literal) {
    return (literal.size() == 3 && literal[0] == '\'' && literal[2] == '\'');
}

bool ScalarConverter::isSpecialLiteral(const std::string& literal) {
    return (literal == "nan" || literal == "nanf" ||
            literal == "inf" || literal == "inff" ||
            literal == "+inf" || literal == "+inff" ||
            literal == "-inf" || literal == "-inff");
}
