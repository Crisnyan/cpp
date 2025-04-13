#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& weapon) : m_name(name), m_weapon(weapon) {
	std::cout << m_name << " created with weapon <" << m_weapon.getType() << ">" << std::endl;
}

HumanA::~HumanA() {
	std::cout << m_name << " destroyed" << std::endl;
}
void HumanA::attack(void) {
	std::cout << m_name << " attacks with their " << m_weapon.getType() << std::endl;
}
