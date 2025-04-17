#include "Fixed.hpp"

Fixed::Fixed(void) {
	m_fixed = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed &other) {
	m_fixed = other.m_fixed;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed &other) {
	if (this != &other)
		m_fixed = other.m_fixed;
	std::cout << "Assignement operator called" << std::endl;
	return (*this);
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits function called" << std::endl;
	return (m_fixed);
}
void Fixed::setRawBits(const int raw) {
	m_fixed = raw;
	std::cout << "setRawBits function called" << std::endl;
}
