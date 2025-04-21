#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
#include <iostream>

class WrongAnimal {
protected:
	std::string m_type;
public:
	WrongAnimal();
	virtual ~WrongAnimal();
	WrongAnimal(const std::string &type);
	WrongAnimal(WrongAnimal const &other);
	WrongAnimal &operator=(WrongAnimal const other);

	virtual void makeSound(void) const;
	std::string getType(void) const;
};

#endif
