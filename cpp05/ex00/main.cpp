#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat Bur;
		Bureaucrat BureaucratX("Burr", 1);
		BureaucratX.increment();
		std::cout << BureaucratX << " incremented its grade successfully" << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e) {
		std::cerr << "Exception thrown: " << e.what() << std::endl;
	}

	try {
		Bureaucrat Bur;
		Bureaucrat BureaucratX("Burr", 1);
		Bur.decrement();
		std::cout << Bur << " decremented its grade successfully" << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e) {
		std::cerr << "Exception thrown: " << e.what() << std::endl;
	}
	return (0);
}
