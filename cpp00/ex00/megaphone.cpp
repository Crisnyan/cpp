#include <iostream>

int printUpper(char c) {
	if (c == '\0')
		return (0);
	if ('a' <= c && c <= 'z')
		std::cout << (char)(c + 'A' - 'a');
	else
		std::cout << c;
	return (1);
}

int	main(int argc, char *argv[]) {
	if (argc == 1)
		return (0);
	for (int i = 1; i < argc; ++i)
		for (int j = 0; printUpper(argv[i][j]) != 0; j++);
	std::cout << std::endl;
	return (0);
}
