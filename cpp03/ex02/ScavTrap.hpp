#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
	ScavTrap();
	ScavTrap(std::string const &name);
	~ScavTrap();
	ScavTrap(ScavTrap const &other);
	ScavTrap &operator=(ScavTrap const &other);
	void guardGate(void);
	void attack(const std::string &target);
};

#endif

