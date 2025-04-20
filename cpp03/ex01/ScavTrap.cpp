#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	m_name = "ScavTrap";
	m_hitpoints = 100;
	m_attackDamage = 20;
	m_energyPoints = 50;
	std::cout << "Default Scav constructor called" << std::endl;
};

ScavTrap::ScavTrap(std::string const &name) : ClapTrap() {
	m_name = name;
	m_hitpoints = 100;
	m_attackDamage = 20;
	m_energyPoints = 50;
	std::cout << "Scav Name constructor called with name: " << m_name << std::endl;
};

ScavTrap::~ScavTrap() {
	std::cout << "Scav Destructor called" << std::endl;
	m_name.~basic_string();
}

ScavTrap::ScavTrap(ScavTrap const &other) : ClapTrap(other) {
	*this = other;
	std::cout << "Scav Copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &other) {
	if (this != &other) {
		m_name = other.getName();
		m_hitpoints = other.getHitpoints();
		m_attackDamage = other.getAttack();
		m_energyPoints = other.getEnergy();
	}
	std::cout << "Scav Assignement operator called" << std::endl;
	return (*this);
}

void ScavTrap::guardGate(void) {
	std::cout << m_name << " is now in Gate Keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string &target) {
	std::cout << "ScavTrap " << m_name << " attacks " << target << " dealing " << m_attackDamage << " points of damage!" << std::endl;
}

