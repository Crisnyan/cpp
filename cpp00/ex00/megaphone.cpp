#include <iostream>

using std::cout, std::endl;

int printUpper(char c)
{
	if (c == '\0')
		return (0);
	if ('a' <= c && c <= 'z')
		cout << (char)(c + 'A' - 'a');
	else
		cout << c;
	return (1);
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
		return (0);
	for (int i = 1; i < argc; ++i)
		for (int j = 0; printUpper(argv[i][j]) != 0; j++);
	cout << endl;
	return (0);
}
