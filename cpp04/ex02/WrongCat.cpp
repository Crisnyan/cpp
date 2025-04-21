#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	m_type = "WrongCat";
	std::cout << "WrongCat constructed" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destroyed" << std::endl;
}

WrongCat::WrongCat(WrongCat const &other) : WrongAnimal(other) {
	m_type = other.getType();
}

WrongCat &WrongCat::operator=(WrongCat const other) {
	if (this != &other)
		m_type = other.getType();
	return (*this);
}

void WrongCat::makeSound(void) const {
	std::cout << m_type << " says \"Vaporeon\"!" << std::endl;
}
