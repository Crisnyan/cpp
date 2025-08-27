#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class AForm;

class Bureaucrat {
private:
	const std::string	m_name;
	unsigned int		m_grade;

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
	Bureaucrat(const std::string name, unsigned int grade);
	~Bureaucrat();
	Bureaucrat &operator=(Bureaucrat const &other);
	Bureaucrat(Bureaucrat const &other);

	unsigned int getGrade() const;
	std::string getName() const;
	void increment();
	void decrement();
	void executeForm(const AForm& form) const;
};

std::ostream &operator<<(std::ostream &stream, const Bureaucrat& Bureaucrat);

#endif
