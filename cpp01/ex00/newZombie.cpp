#include "Zombie.hpp"

Zombie *newZombie(std::string name) {
	Zombie *zomb;

	zomb = new Zombie();
	zomb->setName(name);
	return (zomb);
}
