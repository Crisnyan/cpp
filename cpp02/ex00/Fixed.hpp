#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
class Fixed {
private:
	int					m_fixed;
	static const int	m_fractional = 8;
public:
	Fixed();
	~Fixed();
	Fixed(Fixed &other);
	Fixed &operator=(Fixed &other);
	int getRawBits(void) const;
	void setRawBits(const int raw);
};
#endif
