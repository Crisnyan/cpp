#include "Brain.hpp"

Brain::Brain() {
	for (int i = 0; i < 100; ++i) {
	  m_ideas[i] = "Thinking...";
	}
	std::cout << "Brain created" << std::endl;
}

Brain::~Brain() {
	std::cout << "Brain destroyed" << std::endl;
}

Brain::Brain(Brain const &other) {
	for (int i = 0; i < 100; ++i) {
	  m_ideas[i] = other.getIdea(i);
	}
	std::cout << "Brain copied" << std::endl;
}

Brain &Brain::operator=(Brain other) {
	if (this != &other) {
		for (int i = 0; i < 100; ++i) {
		  m_ideas[i] = other.getIdea(i);
		}
	}
	std::cout << "Brain assigned" << std::endl;
	return (*this);
}

void Brain::setIdea(std::string const &idea, unsigned int pos) {
	if (pos >= 100)
		return ((void)(std::cout << "Brain not big enough" << std::endl));
	m_ideas[pos] = idea;
}

std::string Brain::getIdea(unsigned int pos) const {
	if (pos >= 100) {
		std::cout << "Brain not big enough, returning random idea" << std::endl;
		return (m_ideas[pos % 100]);
	}
	return (m_ideas[pos]);
}
