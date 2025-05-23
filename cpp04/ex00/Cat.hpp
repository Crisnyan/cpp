#ifndef CAT_HPP
# define CAT_HPP
#include "Animal.hpp"

class Cat : public Animal {
public:
	Cat();
	~Cat();
	Cat(const std::string &type);
	Cat(Cat const &other);
	Cat &operator=(Cat const other);

	void makeSound(void) const;
};

#endif
