#include "PmergeMe.hpp"

int main(int argc, char **argv) {

	if (argc == 1)
		return ((void)(std::cerr << "Error: no input" << std::endl), 1);
	try {
		if (argc == 2)
			PmergeMe pmm(argv[1]);
		else
			PmergeMe pmm(argv);
	}

	catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}
