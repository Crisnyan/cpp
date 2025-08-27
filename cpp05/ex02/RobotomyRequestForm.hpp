#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
	void doForm(const Bureaucrat &bur) const;
public:
	RobotomyRequestForm();
};

#endif
