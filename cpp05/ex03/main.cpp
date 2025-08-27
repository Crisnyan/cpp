#include "Intern.hpp"

int main() {

	std::string cont;
	AForm *ref;
	try {
		Intern bob;
		AForm *SC = bob.makeForm("shrubbery creation", "bob");
		ref = SC;
		Bureaucrat buro;
		std::cout << std::endl;

		SC->beSigned(buro);
		std::cout << std::endl;
		SC->execute(buro);
		std::cout << std::endl;
		delete SC;
	}
	catch (const std::exception& e) {
		std::cerr << std::endl;
		std::cerr << "Exception: " << e.what() << std::endl;
		delete ref;
		std::cerr << std::endl;
	}
	catch (...) {
		std::cerr << std::endl;
		std::cerr << "unknown exception caught" << std::endl;
		delete ref;
		std::cerr << std::endl;
	}
	std::cout << "Press any key to continue:" << std::endl;
	std::cin >> cont;

	try {
		Intern bob;
		AForm *SC = bob.makeForm("shrubbery creation", "mr.crab");
		ref = SC;
		Bureaucrat bur("john", 1);
		std::cout << std::endl;

		SC->beSigned(bur);
		std::cout << std::endl;
		SC->execute(bur);
		std::cout << std::endl;
		delete SC;
	}
	catch (const std::exception& e) {
		std::cerr << std::endl;
		std::cerr << "Exception: " << e.what() << std::endl;
		delete ref;
		std::cerr << std::endl;
	}
	catch (...) {
		std::cerr << std::endl;
		std::cerr << "unknown exception caught" << std::endl;
		delete ref;
		std::cerr << std::endl;
	}
	std::cout << "Press any key to continue:" << std::endl;
	std::cin >> cont;

	try {
		Intern bob;
		AForm *RR = bob.makeForm("robotomy request", "beemo");
		ref = RR;
		Bureaucrat bur("john", 1);
		std::cout << std::endl;

		RR->beSigned(bur);
		std::cout << std::endl;
		RR->execute(bur);
		std::cout << std::endl;
		delete RR;
	}
	catch (const std::exception& e) {
		std::cerr << std::endl;
		std::cerr << "Exception: " << e.what() << std::endl;
		delete ref;
		std::cerr << std::endl;
	}
	catch (...) {
		std::cerr << std::endl;
		std::cerr << "unknown exception caught" << std::endl;
		delete ref;
		std::cerr << std::endl;
	}
	std::cout << "Press any key to continue:" << std::endl;
	std::cin >> cont;

	try {
		Intern bob;
		AForm *PP = bob.makeForm("presidential pardon", "hit");
		ref = PP;
		Bureaucrat bur("john", 1);
		std::cout << std::endl;

		PP->beSigned(bur);
		std::cout << std::endl;
		PP->execute(bur);
		std::cout << std::endl;
		delete PP;
	}
	catch (const std::exception& e) {
		std::cerr << std::endl;
		std::cerr << "Exception: " << e.what() << std::endl;
		delete ref;
		std::cerr << std::endl;
	}
	catch (...) {
		std::cerr << std::endl;
		std::cerr << "unknown exception caught" << std::endl;
		delete ref;
		std::cerr << std::endl;
	}
}
