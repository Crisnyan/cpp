#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed {
private:
	int					m_fixed;
	static const int	m_fractional = 8;
public:
	Fixed();
	Fixed(const int num);
	Fixed(const float num);
	~Fixed();
	Fixed(Fixed const &other);
	Fixed &operator=(Fixed const &other);
	int getRawBits(void) const;
	void setRawBits(const int raw);
	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream &operator<<(std::ostream &stream, Fixed const &num);

#endif
