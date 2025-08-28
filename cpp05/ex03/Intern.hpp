#ifndef INTERN_HPP
# define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
private:
	std::string forms[3];
	AForm *(Intern::*f_ptr[3])(const std::string& target);
public:
	Intern();
	~Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);

	AForm *makeForm(const std::string& form_name, const std::string& target);
	AForm *makeShrub(const std::string& target);
	AForm *makeRobot(const std::string& target);
	AForm *makePres(const std::string& target);
};
	
#endif
