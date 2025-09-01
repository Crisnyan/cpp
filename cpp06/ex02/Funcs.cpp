# include "Funcs.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

Base *generate() {
	std::string result;
	A *a = (A *)&result;
	B *b = (B *)&result;
	C *c = (C *)&result;

	std::cout << "Choose a pet between <dog>, <cat> and <bunny>:" << std::endl;
	std::getline(std::cin, result);
	
	if (result == "dog")
		return (a);
	if (result == "cat")
		return (b);
	if (result == "bunny")
		return (c);
	std::cout << "WRONG, TRY AGAIN" << std::endl;
	return (NULL);
}

void identify(Base *p) {
	if (dynamic_cast<A *>(p))
		std::cout << "It's a type A" << std::endl;
	if (dynamic_cast<B *>(p))
		std::cout << "It's a type B" << std::endl;
	if (dynamic_cast<C *>(p))
		std::cout << "It's a type C" << std::endl;
	std::cout << "It's none type" << std::endl;
}

void identify(Base &p) {
	A dog;
	B cat;
	C bun;

	try {
		dog = dynamic_cast<A &>(p);
		std::cout << "It's a type A" << std::endl;
	}
	catch (const std::exception &e) {
	}
	try {
		cat = dynamic_cast<B &>(p);
		std::cout << "It's a type B" << std::endl;
	}
	catch (const std::exception &e) {
	}
	try {
		bun = dynamic_cast<C &>(p);
		std::cout << "It's a type C" << std::endl;
	}
	catch (const std::exception &e) {
	}
	std::cout << "It's none type" << std::endl;
}
