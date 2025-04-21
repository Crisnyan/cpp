#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() : Animal("Cat") {
	m_brain = new Brain;
	std::cout << "Cat constructed" << std::endl;
}

Cat::~Cat() {
	delete m_brain;
	std::cout << "Cat destroyed" << std::endl;
}

Cat::Cat(Cat const &other) : Animal(other) {
	m_brain = new Brain;
	*this = other;
	std::cout << "Cat copied" << std::endl;
}

Cat &Cat::operator=(Cat const other) {
	if (this != &other) {
		m_type = other.getType();
		*m_brain = *other.m_brain;
	}
	std::cout << "Cat assigned" << std::endl;
	return (*this);
}

void Cat::makeSound(void) const {
	std::cout << m_type << " says \"meow\"!" << std::endl;
}

std::string Cat::getThought(unsigned int pos) const {
	return (m_brain->getIdea(pos));
}
