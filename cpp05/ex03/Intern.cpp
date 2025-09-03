#include "Intern.hpp"

Intern::Intern() {
	forms[0] = "shrubbery creation";
	forms[1] = "robotomy request";
	forms[2] = "presidential pardon";
	f_ptr[0] = &Intern::makeShrub;
	f_ptr[1] = &Intern::makeRobot;
	f_ptr[2] = &Intern::makePres;
	std::cout << "Intern created" << std::endl;
}

Intern::~Intern() {
	std::cout << "Intern destroyed" << std::endl;
}

Intern::Intern(const Intern& other) {
	(void)other;
	std::cout << "Intern copied" << std::endl;
}

Intern& Intern::operator=(const Intern& other) {
	std::cout << "Intern assigned" << std::endl;
	(void)other;
	return (*this);
}

AForm *Intern::makeShrub(const std::string& target) {
	std::cout << "Intern creates shrubbery creation form" << std::endl;
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeRobot(const std::string& target) {
	std::cout << "Intern creates robotomy request form" << std::endl;
	return (new RobotomyRequestForm(target));
}

AForm *Intern::makePres(const std::string& target) {
	std::cout << "Intern creates presidential pardon form" << std::endl;
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(const std::string& form_name, const std::string& target){
	AForm *form = NULL;

	for (int i = 0; i < 3; ++i)
		form_name == forms[i] ? (void)(form = (this->*f_ptr[i])(target)) : (void)0;
	form ? (void)0 : (void)(std::cout << "Intern couldn't create a form with name: " << form_name << std::endl);
	return (form);
}
