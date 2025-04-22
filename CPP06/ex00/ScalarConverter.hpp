
#pragma once

#include <string>

class ScalarConverter{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter&);
	ScalarConverter& operator=(const ScalarConverter&);
	~ScalarConverter();

	static bool isChar(const std::string& literal);
	static bool isSpecial(const std::string& literal);
	static void handleChar(const std::string& literal);
	static void handleSpecial(const std::string& literal);
	static void handleNumeric(const std::string& literal);

	
public:
	static void convert(const std::string& literal);

};
