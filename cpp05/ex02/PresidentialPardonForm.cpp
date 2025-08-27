#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5, "base") {
	std::cout << "Base constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 25, 5, target) {
	std::cout << "Base constructor called" << std::endl;
}

void PresidentialPardonForm::doForm(const Bureaucrat& bur) const {
	std::cout << "PresidentialPardonForm is being executed by " << bur.getName() << "!" << std::endl;
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
