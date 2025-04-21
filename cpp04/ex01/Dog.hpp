#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
private:
	Brain *m_brain;
public:
	Dog();
	~Dog();
	Dog(const std::string &type);
	Dog(Dog const &other);
	Dog &operator=(Dog const other);
	void makeSound(void) const;
	std::string getThought(unsigned int pos) const;
};

#endif
