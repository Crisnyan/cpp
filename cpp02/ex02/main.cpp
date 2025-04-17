#include "Fixed.hpp"

int main(void) {
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	Fixed const c(0);

	std::cout << "first: " << a << std::endl;
	std::cout << "second: " << ++a << std::endl;
	std::cout << "third: " << a << std::endl;
	std::cout << "fourth: " << a++ << std::endl;
	std::cout << "fifth: " << a << std::endl;
	std::cout << "sum: " << a + b << std::endl;
	std::cout << "dif: " << a - b << std::endl;
	std::cout << "mult: " << a * b << std::endl;
	std::cout << "div: " << a / b << std::endl;
	std::cout << "div: " << a / c << std::endl;

	std::cout << b << std::endl;
	std::cout << "max: " << Fixed::max(a, b) << std::endl;
	std::cout << "min: " << Fixed::min(a, b) << std::endl;
	return (0);
}
