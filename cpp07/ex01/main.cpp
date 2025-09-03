#include "iter.hpp"

static void addprintchar(const char& c) {
	std::cout << (char)(c + 1) << std::endl;
}

static void addprintint (int& c) {
	c += 1;
	std::cout << c << std::endl;
}

int main()
{
	const char str[] = "abcd";
	int num[4] = {1,2,3,4};

	std::cout << "---Start---" << std::endl;
	iter((char *)NULL, 4, addprintchar);
	std::cout << std::endl;
	iter(num, 0, addprintint);
	std::cout << std::endl;
	iter(num, 4, reinterpret_cast<void(*)(int&)>(0));
	std::cout << std::endl;
	iter(str, 4, addprintchar);
	std::cout << std::endl;
	iter(num, 4, addprintint);
}
