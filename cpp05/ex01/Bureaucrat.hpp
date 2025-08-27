#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat {
private:
	const std::string	m_name;
	int					m_grade;

public:
	class GradeTooHighException : public std::exception {
		public:
			char const *what() const throw();
	};

	class GradeTooLowException : public std::exception {
		public:
			char const *what() const throw();
	};

	Bureaucrat();
	Bureaucrat(const std::string name, int grade);
	~Bureaucrat();
	Bureaucrat &operator=(Bureaucrat const &other);
	Bureaucrat(Bureaucrat const &other);

	unsigned int getGrade() const;
	std::string getName() const;
	void increment();
	void decrement();
};

std::ostream &operator<<(std::ostream &stream, const Bureaucrat& Bureaucrat);

# endif
