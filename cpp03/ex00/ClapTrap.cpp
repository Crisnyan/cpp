#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : m_name("ClapTrap"), m_hitpoints(5), m_attackDamage(2), m_energyPoints(3) {
	std::cout << "Default constructor called" << std::endl;
};

ClapTrap::ClapTrap(std::string const &name) : m_name(name), m_hitpoints(5), m_attackDamage(2), m_energyPoints(3) {
	std::cout << "Name constructor called with name: " << m_name << std::endl;
};

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called" << std::endl;
	m_name.~basic_string();
}

ClapTrap::ClapTrap(ClapTrap const &other) {
	*this = other;
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &other) {
	if (this != &other) {
		m_name = other.getName();
		m_hitpoints = other.getHitpoints();
		m_attackDamage = other.getAttack();
		m_energyPoints = other.getEnergy();
	}
	std::cout << "Assignement operator called" << std::endl;
	return (*this);
}

std::string ClapTrap::getName(void) const {
	return (m_name);
}

unsigned int ClapTrap::getHitpoints(void) const {
	return (m_hitpoints);
}

unsigned int ClapTrap::getAttack(void) const {
	return (m_attackDamage);
}

unsigned int ClapTrap::getEnergy(void) const {
	return (m_energyPoints);
}

void ClapTrap::attack(const std::string &target) {
	if (m_energyPoints > 0)
		std::cout << m_name << " attacked " << target << " dealing " << m_attackDamage << " points of damage!" << std::endl;
	else {
		std::cout << m_name << " has no energy left to attack!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (!m_hitpoints) {
		std::cout << m_name << " is dead!" << std::endl;
		return ;
	}
	if (amount >= m_hitpoints) {
		std::cout << m_name << " has taken " << m_hitpoints << " hitpoints of damage!" << std::endl;
		m_hitpoints = 0;
		return ;
	}
	m_hitpoints -= amount;
	std::cout << m_name << " has taken " << amount << " hitpoints of damage!" << std::endl;
	
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (m_energyPoints > 0)
		m_hitpoints += amount;
	else {
		std::cout << m_name << " has no energy left to repair itself!" << std::endl;
	}
}
