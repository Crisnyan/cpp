#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog constructed" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog destroyed" << std::endl;
}

Dog::Dog(Dog const &other) : Animal(other) {
	std::cout << "Dog copied" << std::endl;
}

Dog &Dog::operator=(Dog const other) {
	if (this != &other)
		Animal::operator=(other);
	return (*this);
}

void Dog::makeSound(void) const {
	std::cout << m_type << " says \"woof\"!" << std::endl;
}
