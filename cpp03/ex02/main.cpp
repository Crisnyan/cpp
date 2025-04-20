#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void) {
	ClapTrap Clapper;
	ScavTrap Scav("Scav");
	FragTrap Frag("Frag");

	Frag.attack(Scav.getName());
	Scav.attack(Clapper.getName());
	Clapper.attack(Frag.getName());

	Scav.guardGate();
	Frag.highFivesGuys();
}
