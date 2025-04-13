#include "Weapon.hpp"

Weapon::Weapon() {
	m_type = "None";
	std::cout << "Weapon created" << std::endl;
}

Weapon::Weapon(const std::string& type) {
	m_type = type;
	std::cout << "Weapon created" << std::endl;
}

Weapon::~Weapon() {
	std::cout << "Weapon destroyed" << std::endl;
}

std::string& Weapon::getType(void) {
	return (m_type);
}

void Weapon::setType(const std::string &type) {
	m_type = type;
}
