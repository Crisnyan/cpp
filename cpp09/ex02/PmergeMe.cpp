/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:39:29 by adrmarqu          #+#    #+#             */
/*   Updated: 2025/04/21 14:34:04 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <climits>

PmergeMe::~PmergeMe() {
}

PmergeMe::PmergeMe(PmergeMe const &other) : m_input(other.m_input), m_vector(other.m_vector), m_deque(other.m_deque) {
}

PmergeMe	&PmergeMe::operator=(PmergeMe const &other) {
	if (this != &other)	{
		m_input = other.m_input;
		m_vector = other.m_vector;
		m_deque = other.m_deque;
	}
	return *this;
}

PmergeMe::PmergeMe(std::string input) {
	std::string			str;
	std::istringstream	iss(input);

	if (input.empty())
		throw std::invalid_argument("empty argument");
	while (iss >> str)
		checkInput(str);
	handleProgram();
}

PmergeMe::PmergeMe(char **input) {
	for (int i = 1; input[i]; i++)
		checkInput(input[i]);
	m_input.erase(0, 1);

	handleProgram();
}

void	PmergeMe::handleProgram() {
	double	timeV = sortAndTime(m_vector);
	double	timeD = sortAndTime(m_deque);
	
	display(timeV, timeD);
}

void	PmergeMe::checkInput(std::string str) {
	double	num = 0;

	checkSign(str);
	
	for (int i = 0; i < static_cast<int>(str.length()); i++) {
		if (!std::isdigit(str[i]))
			throw std::invalid_argument("only positive integers => " + str);
		num = num * 10 + (str[i] - '0');
	}

	if (num > UINT_MAX || str.length() > 10)
		throw std::invalid_argument("uint overflow => " + str);

	m_input += " ";
	m_input += str;
}

void	PmergeMe::checkSign(std::string &str) {
	int			idx = 0;
	bool		negative = false;
	std::string	tmp(str);

	if (str[0] == '-')
		negative = true;
	for (int i = 0; str[i] == '-'; i++)
		idx++;
	str.erase(0, idx);
	
	if (idx && !std::isdigit(str[0]))
		throw std::invalid_argument("bad input => " + tmp);
	
	if (negative && std::atoi(str.c_str()) != 0)
		throw std::invalid_argument("negative number => -" + str);
	
	idx = 0;
	for (int i = 0; str[i] == '+'; i++)
		idx++;
	str.erase(0, idx);
	
	if (idx && !std::isdigit(str[0]))
		throw std::invalid_argument("bad input => " + tmp);
}

void	PmergeMe::display(double v, double d) const {
	std::cout << "Before:\t" << m_input << std::endl;

	std::cout << "After:\t";
	std::cout << m_vector[0];
	for (unsigned int i = 1; i < m_vector.size(); i++)
		std::cout << " " <<  m_vector[i];
	std::cout << std::endl;

	std::cout << "Time to process a range of " << m_vector.size() <<
		" elements with std::vector<unsigned int> :  " << v << " us" << std::endl;

	std::cout << "Time to process a range of " << m_deque.size() <<
		" elements with std::deque<unsigned int> :  " << d << " us" << std::endl;
}

