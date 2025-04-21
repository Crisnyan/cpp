#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
	WrongCat();
	~WrongCat();
	WrongCat(const std::string &type);
	WrongCat(WrongCat const &other);
	WrongCat &operator=(WrongCat const other);

	void makeSound(void) const;
};

#endif
