#include "HumanB.hpp"

HumanB::HumanB(std::string name) : m_name(name) {
	std::cout << m_name << " created" << std::endl;
}

HumanB::~HumanB() {
	std::cout << m_name << " destroyed" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
	m_weapon = &weapon;
}

void HumanB::attack(void) {
	std::cout << m_name << " attacks with their " << m_weapon->getType() << std::endl;
}
