#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try {
		Form basic;
		Form FormX("X", 100, 0);
	}
	catch (const Form::GradeTooHighException &e) {
		std::cerr << "Exception thrown: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		Form basic;
		Form FormX("X", 100, 151);

	}
	catch (const Form::GradeTooLowException &e) {
		std::cerr << "Exception thrown: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	Bureaucrat bur;
	Bureaucrat BurX("BurX", 1);
	Form basic;
	Form FormX("X", 100, 150);
	std::cout << std::endl;

	basic.beSigned(bur);
	basic.beSigned(BurX);
	std::cout << std::endl;
	FormX.beSigned(bur);
	FormX.beSigned(BurX);
	std::cout << std::endl;
	return (0);
}
