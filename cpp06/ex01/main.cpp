#include "Serializer.hpp"

int main() {
	Data *dataptr = new Data;
	uintptr_t serialized_data = 0x0;
	Data *unserialized_data = 0x0;

	dataptr->name = "Juan";
	dataptr->age = 20;

	//NOTE: If we serialize then deserialize and check the data is the same then it's a success
	
	serialized_data = Serializer::serialize(dataptr);
	unserialized_data = Serializer::deserialize(serialized_data);

	std::cout << "Name before: " << dataptr->name << std::endl;
	std::cout << "Name after: " << unserialized_data->name << std::endl;
	std::cout << std::endl;
	std::cout << "Age before: " << dataptr->age << std::endl;
	std::cout << "Age after: " << unserialized_data->age << std::endl;
	delete dataptr;
}
