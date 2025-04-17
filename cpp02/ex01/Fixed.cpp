#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) {
	m_fixed = 0;
	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const int num) {
	m_fixed = (num << m_fractional);
	std::cout << "Int constructor called" << std::endl;
}
Fixed::Fixed(const float num) {
	m_fixed = round(num * (1 << m_fractional));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &other) {
	m_fixed = other.m_fixed;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &other) {
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

float Fixed::toFloat(void) const {
	return (static_cast<float>(m_fixed) / (1 << m_fractional));
}

int Fixed::toInt(void) const {
	if (!(m_fixed >> (m_fractional - 1) & 1))
		return (m_fixed >> m_fractional);
	return ((m_fixed >> m_fractional) + 1);
}

std::ostream &operator<<(std::ostream &stream, Fixed const &num) {
	stream << num.toFloat();
	return (stream);
}
