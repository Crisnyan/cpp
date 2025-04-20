#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
	FragTrap();
	FragTrap(std::string const &name);
	~FragTrap();
	FragTrap(FragTrap const &other);
	FragTrap &operator=(FragTrap const &other);
	void attack(const std::string &target);
	void highFivesGuys(void) const;
};

#endif

