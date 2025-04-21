#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	m_name = "FragTrap";
	m_hitpoints = 100;
	m_attackDamage = 30;
	m_energyPoints = 100;
	std::cout << "Default Frag constructor called" << std::endl;
};

FragTrap::FragTrap(std::string const &name) : ClapTrap() {
	m_name = name;
	m_hitpoints = 100;
	m_attackDamage = 30;
	m_energyPoints = 100;
	std::cout << "Frag Name constructor called with name: " << m_name << std::endl;
};

FragTrap::~FragTrap() {
	std::cout << "Frag Destructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap const &other) : ClapTrap(other) {
	*this = other;
	std::cout << "Frag Copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &other) {
	if (this != &other) 
		ClapTrap::operator=(other);
	std::cout << "Frag Assignement operator called" << std::endl;
	return (*this);
}

void FragTrap::highFivesGuys(void) const {
	std::cout << m_name << " has positively requested to high five five guys?" << std::endl;
}

void FragTrap::attack(const std::string &target) {
	std::cout << "FragTrap " << m_name << " attacks " << target << " dealing " << m_attackDamage << " points of damage!" << std::endl;
}

