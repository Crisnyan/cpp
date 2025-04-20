#include "ClapTrap.hpp"

int main(void) {
	ClapTrap Claptrap;
	ClapTrap Clappy("Clappy");
	ClapTrap Clappy2(Clappy);

	Claptrap = ClapTrap("John");
	for (int i = 0; i < 5; ++i) {
	Clappy.attack(Claptrap.getName());
	Claptrap.takeDamage(Clappy.getAttack());
	std::cout << Claptrap.getName() << " has " << Claptrap.getHitpoints() << " hitpoints left!" << std::endl;
	Claptrap.attack(Clappy.getName());
	Clappy.takeDamage(Claptrap.getAttack());
	std::cout << Clappy.getName() << " has " << Clappy.getHitpoints() << " hitpoints left!" << std::endl;
	}
}
