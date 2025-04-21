#include "Dog.hpp"
#include "Cat.hpp"

int main(void) {
	const Animal *AnimArray[100];

	std::cout << "First index" << std::endl;
	for (int i = 0; i < 50; ++i) {
		AnimArray[i] = new Dog;
	}
	std::cout << "Fiftieth index" << std::endl;
	for (int i = 50; i < 100; ++i) {
		AnimArray[i] = new Cat;
	}
	std::cout << "Hundreth index" << std::endl;
	for (int i = 0; i < 100; ++i) {
		delete AnimArray[i];
	}
	return (0);
}
