#include "Zombie.hpp"

void	randomChump(std::string name) {
	Zombie zomb;

	zomb.setName(name);
	zomb.announce();
}
