#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat constructed" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat destroyed" << std::endl;
}

Cat::Cat(Cat const &other) : Animal(other) {
	std::cout << "Cat copied" << std::endl;
}

Cat &Cat::operator=(Cat const other) {
	if (this != &other)
		Animal::operator=(other);
	return (*this);
}

void Cat::makeSound(void) const {
	std::cout << m_type << " says \"meow\"!" << std::endl;
}
