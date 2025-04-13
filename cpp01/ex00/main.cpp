#include "Zombie.hpp"

int main(void) {
	Zombie *zomb;

	randomChump("Zom");
	zomb = newZombie("Zomb");
	zomb->announce();
	delete zomb;
	return (0);
}
