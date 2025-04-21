#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	m_type = "WrongAnimal";
	std::cout << "WrongAnimal constructed" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destroyed" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &other) {
	m_type = other.getType();
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const other) {
	if (this != &other)
		m_type = other.getType();
	return (*this);
}

void WrongAnimal::makeSound(void) const {
	std::cout << m_type << " says \"E-d-w-a-r-d...\"" << std::endl;
}

std::string WrongAnimal::getType(void) const {
	return (m_type);
}
