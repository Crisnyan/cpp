#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("PresidentialPardonForm", 25, 5, "base") {
	std::cout << "Base constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "Destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137, target) {
	std::cout << "Parametrized constructor called" << std::endl;
}

void RobotomyRequestForm::doForm(const Bureaucrat& bur) const {
	std::srand(std::time(0));

	std::cout << "RobotomyRequestForm is being executed by " << bur.getName() << "!" << std::endl;
	if (std::rand() % 2)
		return ((void)(std::cout << "Congratulations! The robotomy was successful on " <<  this->getTarget() << "!" << std::endl));
	std::cout << "Sadly, the robotomy was unsuccessful on " <<  this->getTarget() << "..." << std::endl;
}
