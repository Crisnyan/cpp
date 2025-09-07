#include "BitcoinExchange.hpp"
#include <fstream>

int main(int argc, char **argv) {
	if (argc < 2)
		return ((void)(std::cerr << "Could not open file" << std::endl), 1);
	if (argc > 2)
		return ((void)(std::cerr << "Too many arguments: 1 needed" << std::endl), 1);

	BitcoinExchange be(argv[1]);
}	
