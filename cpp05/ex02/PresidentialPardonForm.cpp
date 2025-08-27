#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5) {
	std::cout << "Base constructor called" << std::endl;
}

void PresidentialPardonForm::doForm(const Bureaucrat& bur) const {
	std::cout << "PresidentialPardonForm is being Executed!" << std::endl;
	std::cout << bur.getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
