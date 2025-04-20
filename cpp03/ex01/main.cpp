#include "ScavTrap.hpp"

int main(void) {
	ClapTrap Clapper;
	ScavTrap Scavy1("Scavy");
	ScavTrap Scavy2(Scavy1);

	Scavy1.attack(Scavy2.getName());
	Clapper.attack(Scavy2.getName());

	Scavy2.guardGate();
}
