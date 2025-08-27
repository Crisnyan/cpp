#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137, "base") {
	std::cout << "Base constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137, target) {
	std::cout << "Parametrized constructor called" << std::endl;
}

void ShrubberyCreationForm::doForm(const Bureaucrat& bur) const {
	std::ofstream outfile((this->getTarget() + "_shrubbery").c_str());

	std::cout << "ShrubberyCreationForm is being executed by " << bur.getName() << "!" << std::endl;
	outfile		<< "  ***  " << std::endl
				<< " ***** " << std::endl
				<< "*******" << std::endl
				<< " ***** " << std::endl
				<< "  |||  " << std::endl
				<< "  |||  " << std::endl
				<< "  |||  " << std::endl
				<< "  /|\\  " << std::endl;
	outfile.close();
}
