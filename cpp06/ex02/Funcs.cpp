# include "Funcs.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

Base *generate() {
	std::string result;

	std::cout << "Choose a pet between <dog>, <cat> and <bunny>:" << std::endl;
	std::getline(std::cin, result);
	
	if (result == "dog")
		return (new A);
	if (result == "cat")
		return (new B);
	if (result == "bunny")
		return (new C);
	std::cout << "WRONG, TRY AGAIN" << std::endl;
	return (NULL);
}

void identify(Base *p) {
	if (dynamic_cast<A *>(p))
		return ((void)(std::cout << "It's a type A" << std::endl));
	if (dynamic_cast<B *>(p))
		return ((void)(std::cout << "It's a type B" << std::endl));
	if (dynamic_cast<C *>(p))
		return ((void)(std::cout << "It's a type C" << std::endl));
	std::cout << "It's none type" << std::endl;
}

void identify(Base &p) {
	try {
		(void)dynamic_cast<A &>(p);
		std::cout << "It's a type A" << std::endl;
		return ;
	}
	catch (const std::exception &e) {
	}
	try {
		(void)dynamic_cast<B &>(p);
		std::cout << "It's a type B" << std::endl;
		return ;
	}
	catch (const std::exception &e) {
	}
	try {
		(void)dynamic_cast<C &>(p);
		std::cout << "It's a type C" << std::endl;
		return ;
	}
	catch (const std::exception &e) {
	}
	std::cout << "It's none type" << std::endl;
}
