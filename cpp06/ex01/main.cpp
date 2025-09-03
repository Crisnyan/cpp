#include "Serializer.hpp"

int main() {
	Data *dataptr = new Data;
	uintptr_t serialized_data = 0x0;
	Data *unserialized_data = 0x0;

	dataptr->m_name = "Juan";
	dataptr->m_age = 20;

	//NOTE: If we serialize then deserialize and check the data is the same then it's a success
	

	std::cout << "name before: " << dataptr->m_name << std::endl;
	std::cout << "age before: " << dataptr->m_age << std::endl;
	serialized_data = Serializer::serialize(dataptr);
	std::cout << std::endl;
	std::cout << "serialized data: " << serialized_data << std::endl;
	std::cout << std::endl;
	unserialized_data = Serializer::deserialize(serialized_data);
	std::cout << "name after: " << unserialized_data->m_name << std::endl;
	std::cout << "age after: " << unserialized_data->m_age << std::endl;
	delete dataptr;
}
