#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("PresidentialPardonForm", 25, 5) {
	std::cout << "Base constructor called" << std::endl;
}

void RobotomyRequestForm::doForm(const Bureaucrat& target) const {
	std::srand(std::time(0));

	std::cout << "RobotomyRequestForm is being Executed!" << std::endl;
	if (std::rand() % 2)
		return ((void)(std::cout << "Congratulations! The robotomy was successful on " <<  target.getName() << "!" << std::endl));
	std::cout << "Sadly, the robotomy was unsuccessful on " <<  target.getName() << "..." << std::endl;
}
