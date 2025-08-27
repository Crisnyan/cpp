#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
	void doForm(const Bureaucrat &bur) const;
public:
	PresidentialPardonForm();
	~PresidentialPardonForm();
	PresidentialPardonForm(const std::string& target);
};

#endif
