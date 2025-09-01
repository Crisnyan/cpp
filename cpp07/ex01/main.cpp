#include <iostream>
#include "iter.hpp"

static void addprintchar(char c) {
	std::cout << (char)(c + 1) << std::endl;
}

static void addprintint (int c) {
	std::cout << c + 1 << std::endl;
}

int main()
{
	const char str[] = "abcd";
	const int num[4] = {1,2,3,4};

	iter(str, 4, addprintchar);
	std::cout << std::endl;
	iter(num, 4, addprintint);
}
