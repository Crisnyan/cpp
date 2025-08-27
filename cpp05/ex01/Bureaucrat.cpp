#include "Bureaucrat.hpp"

char const *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade is too high");
}

char const *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade is too low");
}

Bureaucrat::Bureaucrat() : m_name("Bur"), m_grade(150) {
	std::cout << "Base Bureaucrat constructed with name " << m_name << " and grade " << m_grade  << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : m_name(name), m_grade(grade) {
	if (grade < 1)
		throw (GradeTooHighException());
	if (grade > 150)
		throw (GradeTooLowException());
	std::cout << "Bureaucrat constructed with name " << m_name << " and grade " << m_grade  << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat with name " << m_name << " and grade " << m_grade  << " destroyed" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other) {
	if (this != &other)
	{
		m_grade = other.getGrade();
	}
	return (*this);
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : m_name(other.getName()), m_grade(other.getGrade()) {
	std::cout << "Copy operator called for Bureaucrat with name " << m_name << " and grade " << m_grade  << std::endl;
}

unsigned int Bureaucrat::getGrade() const {
	return (this->m_grade);
}

std::string Bureaucrat::getName() const {
	return (this->m_name);
}

void Bureaucrat::increment() {
	if (m_grade - 1 < 1)
		throw (GradeTooHighException());
	--m_grade;
}

void Bureaucrat::decrement() {
	if (m_grade + 1 > 150)
		throw (GradeTooLowException());
	++m_grade;
}

std::ostream &operator<<(std::ostream &stream, const Bureaucrat& Bureaucrat) {
	stream << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade();
	return (stream);
}
