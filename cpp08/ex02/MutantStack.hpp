#ifndef MUTANTSTACK_HPP 
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;

	MutantStack() : std::stack<T>() {std::cout << "Mutant Stack created" << std::endl;};
	~MutantStack() {std::cout << "Mutant Stack destroyed" << std::endl;};
	MutantStack(const MutantStack& other) : std::stack<T>(other){std::cout << "Mutant Stack copied" << std::endl;};
	MutantStack& operator=(const MutantStack& other) {
		std::stack<T>::operator=(other);
		std::cout << "Mutant Stack assigned" << std::endl;
	};

	iterator begin() {
		return this->c.begin();
	};

	const_iterator begin() const {
		return this->c.begin();
	};

	iterator end() {
		return this->c.end();
	};

	iterator end() const {
		return this->c.end();
	};
};
#endif
