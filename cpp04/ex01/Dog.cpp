#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() : Animal("Dog") {
	m_brain = new Brain;
	std::cout << "Dog constructed" << std::endl;
}

Dog::~Dog() {
	delete m_brain;
	std::cout << "Dog destroyed" << std::endl;
}

Dog::Dog(Dog const &other) : Animal(other) {
	m_brain = new Brain;
	*this = other;
	std::cout << "Dog copied" << std::endl;
}

Dog &Dog::operator=(Dog const other) {
	if (this != &other) {
		Animal::operator=(other);
		*m_brain = *other.m_brain;
	}
	std::cout << "Dog assigned" << std::endl;
	return (*this);
}

void Dog::makeSound(void) const {
	std::cout << m_type << " says \"woof\"!" << std::endl;
}

std::string Dog::getThought(unsigned int pos) const {
	return (m_brain->getIdea(pos));
}
