#include <fstream>
#include <iostream>
#include <string>

static void substitute(std::string &line, const std::string& str, std::string &sub) {
	size_t pos;
	int len;
	int size;


	len = str.size();
	size = sub.size();
	pos = line.find(str);
	while(pos != std::string::npos) {
		for (int i = 0; i < size && i < len; i++)
			line[pos++] = sub[i];
		if (len - size > 0) {
			line.erase(pos, len - size);
		}
		else if (len - size < 0) {
			line.insert(pos, &sub[len]);
		}
		pos = line.find(str, pos);
	}
}

static void replace(std::ifstream &file, std::ofstream &newFile, std::string &s1, std::string &s2) {
	std::string line;

	while (std::getline(file, line)) {
		if (s1 != "" && s2 == "")
			substitute(line, s1, s2);
		else if (s1.find(s2) == std::string::npos && s2.find(s1) == std::string::npos) {
			substitute(line, s1, s2);
		}
		newFile << line << std::endl;		
	}
	std::cout << "Done." << std::endl;
}

int main(int argc, char **argv) {
	std::ifstream file;
	std::ofstream newFile;
	std::string s1;
	std::string s2;

	if (argc != 4)
		return (1);
	file.open(argv[1]);
	newFile.open(std::string(argv[1] + std::string(".replace")).c_str());
	if (!file) {
		std::cout << "file couldn't be opened" << std::endl;
		return (1);
	}
	s1 = argv[2];
	s2 = argv[3];
	replace(file, newFile, s1, s2);
	file.close();
	newFile.close();
	return (0);
}
