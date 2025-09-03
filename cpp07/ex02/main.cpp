#include "Array.hpp"
#include <stdexcept>

int main() {
	Array<int> a;

	try {
		a[0];
	}
	catch(const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}

	Array<std::string> b(2);

	b[0] = "Good";
	b[1] = " Morning!";

	Array<std::string> c(b);
	Array<std::string> d;

	d = c;

	std::cout << "Sizes:" << std::endl;
	std::cout << "a:" << a.size() << std::endl;
	std::cout << "b:" << b.size() << std::endl;
	std::cout << "c:" << c.size() << std::endl;
	std::cout << "d:" << d.size() << std::endl;

	std::cout << std::endl;
	std::cout << "Before:" << std::endl;
	std::cout << "b:" <<b[0] << b[1] << std::endl;
	std::cout << "c:" <<c[0] << c[1] << std::endl;
	std::cout << "d:" <<d[0] << d[1] << std::endl;

	c[1] = " Afternoon!";
	d[1] = " Night!";

	std::cout << std::endl;
	std::cout << "After:" << std::endl;
	std::cout << "b:" <<b[0] << b[1] << std::endl;
	std::cout << "c:" <<c[0] << c[1] << std::endl;
	std::cout << "d:" <<d[0] << d[1] << std::endl;
}
