#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>

class Brain {
private:
	std::string m_ideas[100];
public:
	Brain();
	~Brain();
	Brain(Brain const &other);
	Brain &operator=(Brain other);
	void setIdea(std::string const &idea, unsigned int pos);
	std::string getIdea(unsigned int pos) const;
};

#endif
