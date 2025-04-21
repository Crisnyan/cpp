#include "Animal.hpp"

Animal::Animal() {
	m_type = "Animal";
	std::cout << "Animal constructed" << std::endl;
}

Animal::Animal(std::string const &type) {
	m_type = type;
	std::cout << "Animal constructed with type " << m_type << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal destroyed" << std::endl;
}

Animal::Animal(Animal const &other) {
	m_type = other.getType();
}

Animal &Animal::operator=(Animal const other) {
	if (this != &other)
		m_type = other.getType();
	return (*this);
}

void Animal::makeSound(void) const {
	std::cout << m_type << " says \"( ͡° ͜ʖ ͡°)\"!" << std::endl;
}

std::string Animal::getType(void) const {
	return (m_type);
}
