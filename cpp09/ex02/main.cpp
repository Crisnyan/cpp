#include "PmergeMe.hpp"

int main(int argc, char **argv) {

	try {
	PmergeMe pmm(argc, argv);
	}

	catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}
