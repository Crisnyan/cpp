#include "Form.hpp"

char const *Form::GradeTooHighException::what() const throw() {
		return ("Grade is too high");
	};

char const *Form::GradeTooLowException::what() const throw() {
	return ("Grade is too low");
	};

Form::Form() : m_name("basic form"), m_sign_grade(150), m_execute_grade(50), m_is_signed(false) {
	std::cout << "unparametrized constructor called" << std::endl;
}

Form::Form(const std::string name, const unsigned int sign, const unsigned int exec) : m_name(name), m_sign_grade(sign), m_execute_grade(exec), m_is_signed(false) {
	if (sign < 1 || exec < 1)
		throw (GradeTooHighException());
	if (sign > 150 || exec > 150)
		throw (GradeTooLowException());
	std::cout << "Constructor called for Form with name " << name << ", grade requirement to be signed: " << sign << ", grade required to be executed: " << exec << std::endl;
}

Form::~Form() {
	std::cout << "Destructor called for Form with name " << m_name << ", grade requirement to be signed: " << m_sign_grade << ", grade required to be executed: " << m_execute_grade << std::endl;
}

Form::Form(const Form& other) : m_name(other.getName()), m_sign_grade(other.getSignGrade()), m_execute_grade(other.getExecGrade()), m_is_signed(other.getIsSign()) {
	std::cout << "Copy operator called" << std::endl;
}

Form& Form::operator=(const Form& other) {
	if (this != &other)
	{
		m_is_signed = other.getIsSign();
	}
	return (*this);
}

std::string Form::getName() const {
	return (m_name);
}

unsigned int Form::getSignGrade() const {
	return (m_sign_grade);
}

unsigned int Form::getExecGrade() const {
	return (m_execute_grade);
}

unsigned int Form::getIsSign() const {
	return (m_is_signed);
}

void Form::beSigned(const Bureaucrat& bur) {
	if (bur.getGrade() <= m_sign_grade && !m_is_signed) {
		m_is_signed = true;
		std::cout << bur << " signed " << *this << std::endl;
		return;
	}
	else if (m_is_signed) {
		std::cout << bur << " couldn't sign " << *this << " because it was already signed" << std::endl;
		return;
	}
	std::cout << bur << " couldn't sign " << *this << " because its grade was too low" << std::endl;
}

std::ostream& operator<<(std::ostream &stream, const Form& form) {
	stream << form.getName() << ", grade requirement to be signed: " << form.getSignGrade() << ", grade required to be executed: " << form.getExecGrade() << " and trueness of being signed " << form.getIsSign();
	return (stream);
}

