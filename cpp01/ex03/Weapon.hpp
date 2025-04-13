#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>

class Weapon {
private:
	std::string	m_type;
public:
	Weapon();
	Weapon(const std::string &type);
	~Weapon();
	std::string &getType(void);
	void setType(const std::string &type);
};
#endif
