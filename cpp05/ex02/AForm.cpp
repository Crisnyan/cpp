#include "AForm.hpp"

char const *AForm::GradeTooHighException::what() const throw() {
		return ("Grade is too high");
	};

char const *AForm::GradeTooLowException::what() const throw() {
	return ("Grade is too low");
	};

char const *AForm::NotSignedException::what() const throw() {
	return ("Form is not signed");
}

AForm::AForm() : m_name("basic form"), m_sign_grade(150), m_execute_grade(50), m_is_signed(false) {
	std::cout << "unparametrized constructor called" << std::endl;
}

AForm::AForm(const std::string name, const unsigned int sign, const unsigned int exec) : m_name(name), m_sign_grade(sign), m_execute_grade(exec), m_is_signed(false) { 
	std::cout << "parametrized constructor called" << std::endl;
}

AForm::~AForm() {
	std::cout << "Destructor called for AForm with name " << m_name << ", grade requirement to be signed: " << m_sign_grade << ", grade required to be executed: " << m_execute_grade << std::endl;
}

AForm::AForm(const AForm& other) : m_name(other.getName()), m_sign_grade(other.getSignGrade()), m_execute_grade(other.getExecGrade()), m_is_signed(other.getIsSign()) {
	std::cout << "Copy operator called" << std::endl;
}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other)
	{
		m_is_signed = other.getIsSign();
	}
	return (*this);
}

std::string AForm::getName() const {
	return (m_name);
}

unsigned int AForm::getSignGrade() const {
	return (m_sign_grade);
}

unsigned int AForm::getExecGrade() const {
	return (m_execute_grade);
}

unsigned int AForm::getIsSign() const {
	return (m_is_signed);
}

void AForm::beSigned(const Bureaucrat& bur) {
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

void AForm::execute(const Bureaucrat& bur) const {
	if (this->getExecGrade() < bur.getGrade())
		throw (GradeTooLowException());
	if (!this->getIsSign())
		throw (NotSignedException());
	this->doForm(bur);
}

std::ostream& operator<<(std::ostream &stream, const AForm& form) {
	stream << form.getName() << ", grade requirement to be signed: " << form.getSignGrade() << ", grade required to be executed: " << form.getExecGrade() << " and trueness of being signed " << form.getIsSign();
	return (stream);
}
