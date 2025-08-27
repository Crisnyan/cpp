#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137) {
	std::cout << "Base constructor called" << std::endl;
}

void ShrubberyCreationForm::doForm(const Bureaucrat& bur) const {
	std::ofstream outfile((bur.getName() + "_shrubbery").c_str());

	std::cout << "ShrubberyCreationForm is being Executed!" << std::endl;
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
