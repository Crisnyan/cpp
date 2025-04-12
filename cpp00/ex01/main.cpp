#include "Phonebook.hpp"

int	main(void)
{
	std::string buffer;
	PhoneBook	pb;

	while(1)
	{
		std::getline(std::cin, buffer);
		if (buffer == "ADD")
		{
			pb.checkSpace(pb.i);
			pb.Add(pb.i);
		}
		if (buffer == "SEARCH")
			pb.Search();
		if (buffer == "EXIT")
			return (0);
	}
	return (0);
}
