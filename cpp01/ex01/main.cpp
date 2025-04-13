#include "Zombie.hpp"

int main(void) {
	int	n;
	Zombie *zomb;

	n = 5;
	zomb = zombieHorde(n, "Zomb");
	for (int i = 0; i < n; i++) {
		std::cout << "zombie with number " << i << " is announcing:" << std::endl;
		zomb[i].announce();
	}
	delete[] zomb;
	return (0);
}
