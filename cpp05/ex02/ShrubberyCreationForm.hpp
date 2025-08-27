#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
private:
	void doForm(const Bureaucrat &bur) const;
public:
	ShrubberyCreationForm();
};

#endif
