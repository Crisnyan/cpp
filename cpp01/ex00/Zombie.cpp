#include "Zombie.hpp"

Zombie::Zombie() {
	m_name = "Zombie";
	std::cout << "Zombie created" << std::endl;
}

Zombie::~Zombie() {
	std::cout << m_name << " destroyed" << std::endl;
}
void Zombie::setName(std::string name) {
	m_name = name;
}
void Zombie::announce(void) {
	std::cout << m_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
