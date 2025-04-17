#include "Fixed.hpp"

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

Fixed Fixed::operator+(Fixed const &sum)  const{
	Fixed res;

	res.setRawBits(m_fixed + sum.getRawBits());
	return (res);
}
Fixed Fixed::operator-(Fixed const &dif)  const{
	Fixed res;

	res.setRawBits(m_fixed - dif.getRawBits());
	return (res);
}
Fixed Fixed::operator*(Fixed const &mult) const {
	Fixed res;

	res.setRawBits(static_cast<int>(static_cast<long>(m_fixed) * static_cast<long>(mult.getRawBits())) >> m_fractional);
	return (res);
}
Fixed Fixed::operator/(Fixed const &div) const {
	Fixed res;

	res.setRawBits(static_cast<int>(static_cast<long>(m_fixed) / static_cast<long>(div.getRawBits()) >> m_fractional));
	return (res);
}

bool Fixed::operator>(Fixed const &other) const {
	return (m_fixed > other.getRawBits());
}
bool Fixed::operator<(Fixed const &other) const {
	return (m_fixed < other.getRawBits());
}
bool Fixed::operator>=(Fixed const &other) const {
	return (m_fixed >= other.getRawBits());
}
bool Fixed::operator<=(Fixed const &other) const {
	return (m_fixed <= other.getRawBits());
}
bool Fixed::operator==(Fixed const &other) const {
	return (m_fixed == other.getRawBits());
}
bool Fixed::operator!=(Fixed const &other) const {
	return (m_fixed != other.getRawBits());
}
Fixed &Fixed::operator++() {
	++m_fixed;
	return (*this);
}
Fixed &Fixed::operator--() {
	--m_fixed;
	return (*this);
}
Fixed Fixed::operator++(int) {
	Fixed tmp;

	tmp = *this;
	m_fixed++;
	return (tmp);
}
Fixed Fixed::operator--(int) {
	Fixed tmp;

	tmp = *this;
	m_fixed--;
	return (tmp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	std::cout << "non-const" << std::endl;
	if (a < b)
		return (a);
	return (b);
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b) {
	std::cout << "const" << std::endl;
	if (a < b)
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	std::cout << "non-const" << std::endl;
	if (a > b)
		return (a);
	return (b);
}
Fixed const &Fixed::max(Fixed const &a, Fixed const &b) {
	std::cout << "const" << std::endl;
	if (a > b)
		return (a);
	return (b);
}
