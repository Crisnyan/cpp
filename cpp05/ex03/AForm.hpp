#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class AForm {
private:
	const std::string	m_name;
	const unsigned int	m_sign_grade;
	const unsigned int	m_execute_grade;
	bool				m_is_signed;
	std::string	m_target;
	virtual void doForm(const Bureaucrat& target) const = 0;

public:
	class GradeTooHighException : public std::exception {
		public:
			char const *what() const throw();
	};

	class GradeTooLowException : public std::exception {
		public:
			char const *what() const throw();
	};

	class NotSignedException : public std::exception {
		public:
			char const *what() const throw();
	};

	AForm();
	virtual ~AForm();
	AForm(const std::string name, const unsigned int sign, const unsigned int exec, const std::string& target);
	AForm(const AForm& other);
	AForm &operator=(const AForm& other);

	std::string getName() const;
	unsigned int getSignGrade() const;
	unsigned int getExecGrade() const;
	unsigned int getIsSign() const;
	std::string getTarget() const;
	void beSigned(const Bureaucrat& bur);
	void execute(const Bureaucrat& bur) const;
};

std::ostream& operator<<(std::ostream &stream, const AForm& form);

#endif
