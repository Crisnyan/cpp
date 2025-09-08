#include "PmergeMe.hpp"
#include <cctype>

PmergeMe::PmergeMe() {
	throw std::runtime_error("PmergeMe cannot be initialized without arguments");
};

PmergeMe::PmergeMe(const PmergeMe& other) : m_lst(other.m_lst), m_vec(other.m_vec) {
};

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		this->m_lst = other.m_lst;
		this->m_vec = other.m_vec;
	}
	return (*this);
};

void PmergeMe::setVec(int argc, char **argv) {
	long temp;
	char *end;

	for (int i = 1; i < argc; ++i) {
		temp = strtol(argv[i], &end, 10);
		while (*end) {
			if (!std::isspace(*end))
				break;
			++end;
		}
		if (end == argv[i] || *end)
			throw std::invalid_argument("bad input =>" + static_cast<std::string>(argv[i]));
		if (errno == ERANGE || temp > std::numeric_limits<int>::max() || temp < std::numeric_limits<int>::min())
			throw std::invalid_argument("int overflow");
		if (temp < 0)
			throw std::invalid_argument("negative number");
		m_vec.push_back(static_cast<int>(temp));
	}
};

void PmergeMe::setList(const std::vector<int>& vec) {
	for (int i = 0; i < static_cast<int>(vec.size()); ++i)
		m_lst.push_back((m_vec[i]));
};

PmergeMe::PmergeMe(int argc, char **argv) {
	setVec(argc, argv);
	setList(m_vec);

	std::vector<int>::const_iterator vit = m_vec.begin();
	std::vector<int>::const_iterator veit = m_vec.end();

	std::list<int>::const_iterator lit = m_lst.begin();
	std::list<int>::const_iterator leit = m_lst.end();

	std::cout << "Vector:" << std::endl;
		while (vit != veit) {
			std::cout << *vit << std::endl;
			++vit;
		}

	std::cout << "List:" << std::endl;
		while (lit != leit) {
			std::cout << *lit << std::endl;
			++lit;
		}
};

PmergeMe::~PmergeMe() {
};
