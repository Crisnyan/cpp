#ifndef SERIALIZER_HPP 
# define SERIALIZER_HPP

#include <iostream>

typedef unsigned long uintptr_t;

class Data {
public:
	std::string			name;
	unsigned int		age;
};

class Serializer {
public:
	static uintptr_t serialize(Data *raw);
	static Data *deserialize(uintptr_t raw);
private:
	Serializer();
	~Serializer();
	Serializer(const Serializer& other);
	Serializer &operator=(const Serializer& other);

};
#endif
