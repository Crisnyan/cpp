#ifndef DOG_HPP
# define DOG_HPP
#include "Animal.hpp"

class Dog : public Animal {
public:
	Dog();
	~Dog();
	Dog(const std::string &type);
	Dog(Dog const &other);
	Dog &operator=(Dog const other);
	void makeSound(void) const;
};

#endif
