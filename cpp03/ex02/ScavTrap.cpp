#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("ScavTrap") {
	std::cout << "Default Scav constructor called" << std::endl;
};

ScavTrap::ScavTrap(std::string const &name) : ClapTrap(name) {
	std::cout << "Scav Name constructor called with name: " << m_name << std::endl;
};

ScavTrap::~ScavTrap() {
	std::cout << "Scav Destructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &other) : ClapTrap(other) {
	*this = other;
	std::cout << "Scav Copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &other) {
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "Scav Assignement operator called" << std::endl;
	return (*this);
}

void ScavTrap::guardGate(void) {
	std::cout << m_name << " is now in Gate Keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string &target) {
	std::cout << "ScavTrap " << m_name << " attacks " << target << " dealing " << m_attackDamage << " points of damage!" << std::endl;
}

