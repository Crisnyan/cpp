#include "ScalarConverter.hpp"

static const std::string toChar(const std::string& str) {
	const char *s = str.c_str();

	if (str.length() == 1) {
		if (*s > 127)
			return ("impossible");
		if (std::isprint(*s))
			return (str);
	}
	return ("Not printable");
}

static int toInt(const std::string& str) {
	const char *s = str.c_str();

	return (std::atoi(s));
}

static float toFloat(const std::string& str) {
	const char *s = str.c_str();

	if 
	return (std::atof(s));
}

static double toDouble(const std::string& str) {
	const char *s = str.c_str();

	return (std::atof(s));
}

void ScalarConverter::convert(const std::string& str) {
	std::cout << "char: " << toChar(str) << std::endl;
	std::cout << "int: " << toInt(str);
	std::cout << "float: " << toFloat(str);
	std::cout << "double: " << toDouble(str);
}
