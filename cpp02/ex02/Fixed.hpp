#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
#include <cmath>

class Fixed {
private:
	static const int	m_fractional = 8;
	int	m_fixed;
public:
	Fixed();
	Fixed(const int num);
	Fixed(const float num);
	~Fixed();
	Fixed(Fixed const &other);
	Fixed operator+(Fixed const &sum) const;
	Fixed operator-(Fixed const &dif) const;
	Fixed operator*(Fixed const &mult) const;
	Fixed operator/(Fixed const &div) const;
	Fixed &operator=(Fixed const &other);
	bool operator>(Fixed const &other) const;
	bool operator<(Fixed const &other) const;
	bool operator>=(Fixed const &other) const;
	bool operator<=(Fixed const &other) const;
	bool operator==(Fixed const &other) const;
	bool operator!=(Fixed const &other) const;
	Fixed &operator++();
	Fixed &operator--();
	Fixed operator++(int);
	Fixed operator--(int);

	int getRawBits(void) const;
	void setRawBits(const int raw);
	float toFloat(void) const;
	int toInt(void) const;
	static Fixed &min(Fixed &a, Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static Fixed const &min(Fixed const &a, Fixed const &b);
	static Fixed const &max(Fixed const &a, Fixed const &b);
};

std::ostream &operator<<(std::ostream &stream, Fixed const &num);

#endif
