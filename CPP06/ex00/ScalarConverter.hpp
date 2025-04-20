
#pragma once

#include <string>

class ScalarConverter{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter&);
	ScalarConverter& operator=(const ScalarConverter&);
	~ScalarConverter();

	static void handleChar(const std::string& literal);
	static void handleSpecial(const std::string& literal);
	static void handleNumeric(const std::string& literal);
	static bool isCharLiteral(const std::string& literal);
	static bool isSpecialLiteral(const std::string& literal);
public:
	static void convert(const std::string& literal);

};
