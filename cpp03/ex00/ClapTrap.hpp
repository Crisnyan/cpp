#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

class ClapTrap {
private:
	std::string m_name;
	unsigned int m_hitpoints;
	unsigned int m_attackDamage;
	unsigned int m_energyPoints;
public:
	ClapTrap();
	ClapTrap(std::string const &name);
	~ClapTrap();
	ClapTrap(ClapTrap const &other);
	ClapTrap &operator=(ClapTrap const &other);
	std::string getName(void) const;
	unsigned int getHitpoints(void) const;
	unsigned int getAttack(void) const;
	unsigned int getEnergy(void) const;
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

# endif
