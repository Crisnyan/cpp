#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class Animal {
protected:
	std::string m_type;

public:
	Animal();
	virtual ~Animal();
	Animal(const std::string &type);
	Animal(Animal const &other);
	Animal &operator=(Animal const other);

	virtual void makeSound(void) const = 0;
	std::string getType(void) const;
};

#endif
