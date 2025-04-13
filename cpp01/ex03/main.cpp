#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void) {
{
	Weapon club = Weapon("crude spiked club");

	HumanA bob("Bob", club);
	bob.attack();
	club.setType("some other type of club");
	bob.attack();
}
{
	Weapon club = Weapon("crude spiked club");

	HumanB alice("Alice");
	alice.setWeapon(club);
	alice.attack();
	club.setType("some other type of club");
	alice.attack();
}
	return (0);
}
