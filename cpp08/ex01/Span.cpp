#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <climits>

Span::Span(unsigned int N): m_len(N) {
	std::cout << "Span created" << std::endl;
}

Span::~Span() {
	std::cout << "Span destroyed" << std::endl;
}

Span::Span(Span const &other): m_len(other.m_len), m_span(other.m_span) {
	std::cout << "Span copied" << std::endl;
}

Span	&Span::operator=(Span const &other) {
	if (this != &other) {
		m_len = other.m_len;
		m_span = other.m_span;
		std::cout << "Span assigned" << std::endl;
	}
	return *this;
}

void	Span::addNumber() {
	if (m_span.size() >= m_len)
		throw std::length_error("Max size reached");
	int nbr = generateRandom();
	std::cout << nbr << std::endl;
	m_span.push_back(nbr);
}

void	Span::addNumber(int nbr) {
	if (m_span.size() >= m_len)
		throw std::length_error("Max size reached");
	std::cout << nbr << std::endl;
	m_span.push_back(nbr);
}

void	Span::addNumbers(unsigned int size) {
	for (unsigned int i = 0; i < size; i++)
		addNumber();
}

void	Span::addNumbers(unsigned int size, int nbr) {
	for (unsigned int i = 0; i < size; i++)
		addNumber(nbr);
}

int	Span::generateRandom() {
	std::srand(time(NULL));

	return (std::rand() % 100 - 50);
}

int	Span::shortestSpan() {
	if (m_span.size() < 2)
		throw std::invalid_argument("At least 2 elements needed");
	int diff = std::abs(m_span[0] - m_span[1]);
	for (unsigned int i = 0; i < m_span.size(); i++) {
		for (unsigned int j = 0; j < m_span.size(); j++) {
			if (i == j)
				continue ;
			int tmp = std::abs(m_span[i] - m_span[j]);
			if (tmp < diff)
				diff = tmp;
		}
	}
	return diff;
}

int	Span::longestSpan()
{
	int	min = INT_MAX;
	int	max = INT_MIN;

	if (m_span.size() < 2)
		throw std::invalid_argument("At least 2 elements needed");
	for (unsigned int i = 0; i < m_span.size(); i++) {
		if (min > m_span[i])
			min = m_span[i];
		if (max < m_span[i])
			max = m_span[i];
	}
	return max - min;
}
