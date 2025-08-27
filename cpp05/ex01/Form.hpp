#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Form {
private:
	const std::string	m_name;
	const unsigned int	m_sign_grade;
	const unsigned int	m_execute_grade;
	bool				m_is_signed;

public:
	class GradeTooHighException : public std::exception {
		public:
			char const *what() const throw();
	};

	class GradeTooLowException : public std::exception {
		public:
			char const *what() const throw();
	};

	Form();
	Form(const std::string name, const unsigned int sign, const unsigned int exec);
	~Form();
	Form(const Form& other);
	Form &operator=(const Form& other);

	std::string getName() const;
	unsigned int getSignGrade() const;
	unsigned int getExecGrade() const;
	unsigned int getIsSign() const;
	void beSigned(const Bureaucrat& bur);
};

std::ostream& operator<<(std::ostream &stream, const Form& form);

#endif
