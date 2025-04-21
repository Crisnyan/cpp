#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
private:
	Brain *m_brain;
public:
	Cat();
	~Cat();
	Cat(const std::string &type);
	Cat(Cat const &other);
	Cat &operator=(Cat const other);
	void makeSound(void) const;
	std::string getThought(unsigned int pos) const;
};

#endif
