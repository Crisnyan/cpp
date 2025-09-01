#include "whatever.hpp"
#include <string>
#include <iostream>

int main() {
	std::string s1 = "hello";
	std::string s2 = "ohell";
	int			x = 1;
	int			y = -1;

	std::cout << "max is: " << ::max(s1, s2) << " " << ::max(x, y) << std::endl;
	std::cout << "min is: " << ::min(s1, s2) << " " << ::min(x, y) << std::endl;
	std::cout << std::endl;
	std::cout << "swap before strings: " << s1 << ", " << s2 << std::endl;
	::swap(s1,s2);
	std::cout << "swap after strings: " << s1 << ", " << s2 << std::endl;
	std::cout << std::endl;
	std::cout << "swap before ints: " << x << ", " << y << std::endl;
	::swap(x,y);
	std::cout << "swap after ints: " << x << ", " << y << std::endl;
}
