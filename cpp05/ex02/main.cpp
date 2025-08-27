#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {

	std::string cont;
	try {
		ShrubberyCreationForm SC;
		Bureaucrat buro;
		std::cout << std::endl;

		SC.beSigned(buro);
		std::cout << std::endl;
		SC.execute(buro);
		std::cout << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << std::endl;
		std::cerr << "Exception: " << e.what() << std::endl;
		std::cerr << std::endl;
	}
	catch (...) {
		std::cerr << std::endl;
		std::cerr << "unknown exception caught" << std::endl;
		std::cerr << std::endl;
	}
	std::cout << "Press any key to continue:" << std::endl;
	std::cin >> cont;

	try {
		ShrubberyCreationForm SC("mr.crab");
		Bureaucrat bur("john", 1);
		std::cout << std::endl;

		SC.beSigned(bur);
		std::cout << std::endl;
		SC.execute(bur);
		std::cout << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << std::endl;
		std::cerr << "Exception: " << e.what() << std::endl;
		std::cerr << std::endl;
	}
	catch (...) {
		std::cerr << std::endl;
		std::cerr << "unknown exception caught" << std::endl;
		std::cerr << std::endl;
	}
	std::cout << "Press any key to continue:" << std::endl;
	std::cin >> cont;

	try {
		RobotomyRequestForm RR("beemo");
		Bureaucrat bur("john", 1);
		std::cout << std::endl;

		RR.beSigned(bur);
		std::cout << std::endl;
		RR.execute(bur);
		std::cout << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << std::endl;
		std::cerr << "Exception: " << e.what() << std::endl;
		std::cerr << std::endl;
	}
	catch (...) {
		std::cerr << std::endl;
		std::cerr << "unknown exception caught" << std::endl;
		std::cerr << std::endl;
	}
	std::cout << "Press any key to continue:" << std::endl;
	std::cin >> cont;

	try {
		PresidentialPardonForm PP("hit");
		Bureaucrat bur("john", 1);
		std::cout << std::endl;

		PP.beSigned(bur);
		std::cout << std::endl;
		PP.execute(bur);
		std::cout << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << std::endl;
		std::cerr << "Exception: " << e.what() << std::endl;
		std::cerr << std::endl;
	}
	catch (...) {
		std::cerr << std::endl;
		std::cerr << "unknown exception caught" << std::endl;
		std::cerr << std::endl;
	}
}
