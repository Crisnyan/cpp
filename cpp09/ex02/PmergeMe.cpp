#include "PmergeMe.hpp"
#include <stdexcept>
#include <ctime>
#include <limits>
#include <cerrno>
#include <cstdlib>
#include <utility>

PmergeMe::PmergeMe() {
	throw std::runtime_error("PmergeMe cannot be initialized without arguments");
};

PmergeMe::PmergeMe(const PmergeMe& other) {
	(void)other;
};

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	(void)other;
	return (*this);
};

void PmergeMe::setVec(std::vector<int>& vec, int argc, char **argv) {
	long temp;
	char *end;

	for (int i = 1; i < argc; ++i) {
		temp = strtol(argv[i], &end, 10);
		while (*end && std::isspace(*end))
			++end;
		if (end == argv[i] || *end)
			throw std::invalid_argument("bad input => " + static_cast<std::string>(argv[i]));
		if (errno == ERANGE || temp > std::numeric_limits<int>::max() || temp < std::numeric_limits<int>::min())
			throw std::invalid_argument("int overflow");
		if (temp < 0)
			throw std::invalid_argument("negative number");
		vec.push_back(static_cast<int>(temp));
	}
};

void PmergeMe::setList(std::list<int>& lst, const std::vector<int>& vec) {
	for (int i = 0; i < static_cast<int>(vec.size()); ++i)
		lst.push_back((vec[i]));
};

std::vector<std::pair<int, int> > PmergeMe::vecPairs(std::vector<int>& vec, int& extra) {
	std::vector<std::pair<int, int> > pairs;
	int a, b;

	a = 0, b = 0, extra = 0;
	for (int i = 0; i < static_cast<int>(vec.size()); ++i) {
		a ? b = vec[i] : a = vec[i];
		if (a && b) {
			a < b ? pairs.push_back(std::make_pair(a,b)) : pairs.push_back(std::make_pair(b,a));
			a = 0, b = 0;
		}
	}
	if (vec.size() % 2)
		extra = vec[static_cast<int>(vec.size() - 1)];
	std::vector<std::pair<int, int> >::const_iterator vit = pairs.begin();
	std::vector<std::pair<int, int> >::const_iterator veit = pairs.end();

	std::cout << "Vector after pairing:" << std::endl;
		while (vit != veit) {
			std::cout << vit->first << ", " << vit->second << std::endl;
			++vit;
		}
	std::cout << extra << std::endl;
	return (pairs);
}

std::list<std::pair<int, int> > PmergeMe::listPairs(std::list<int>& lst, int& extra) {
	std::list<std::pair<int, int> > pairs;
	std::list<int>::const_iterator lit = lst.begin();
	std::list<int>::const_iterator leit = lst.end();
	int a, b;


	a = 0, b = 0, extra = 0;
	while (lit != leit) {
		a ? b = *lit : a = *lit;
		if (a && b) {
			a < b ? pairs.push_back(std::make_pair(a,b)) : pairs.push_back(std::make_pair(b,a));
			a = 0, b = 0;
		}
		++lit;
	}
	if (lst.size() % 2)
		extra = *(--lit);

	std::list<std::pair<int, int> >::const_iterator it = pairs.begin();
	std::list<std::pair<int, int> >::const_iterator eit = pairs.end();

	std::cout << "List after pairing:" << std::endl;
		while (it != eit) {
			std::cout << it->first << ", " << it->second << std::endl;
			++it;
		}

	std::cout << extra << std::endl;
	return (pairs);
}

void PmergeMe::orderVec(std::vector<int>& vec) {
	int extra = 0;
	std::vector<std::pair<int, int> > pairs = vecPairs(vec, extra);
	std::vector<int> small, big;
	
	if (vec.size() <= 1)
		return ;
	for (int i = 0; i < static_cast<int>(pairs.size()); ++i) {
		small.push_back(pairs[i].first);
		big.push_back(pairs[i].second);
	}
	big.push_back(extra);
	std::cout << "Small ";
	printVec(small);
	std::cout << "Big ";
	printVec(big);
};

void PmergeMe::recList(std::list<int>& big) {
	int extra = 0;
	std::list<std::pair<int, int> > pairs = listPairs(big, extra);
	std::list<std::pair<int, int> >::const_iterator lit = pairs.begin();
	std::list<std::pair<int, int> >::const_iterator leit = pairs.end();
	std::list<int> insert;
	if (big.size() == 1)
		return ;
	while (lit != leit) {
		insert.push_back(lit->first);
		big.push_back(lit->second);
		++lit;
	}
	big.push_back(extra);
	recList(big);

	std::list<int>::const_iterator it = insert.begin();
	std::list<int>::const_iterator eit = insert.end();
	while (it != eit) {
		big.push_front(*it);
	}
}

void PmergeMe::orderList(std::list<int>& lst) {
	int extra = 0;
	std::list<std::pair<int, int> > pairs = listPairs(lst, extra);
	std::list<std::pair<int, int> >::const_iterator lit = pairs.begin();
	std::list<std::pair<int, int> >::const_iterator leit = pairs.end();
	std::list<int> small, big;
	if (lst.size() <= 1)
		return ;
	while (lit != leit) {
		small.push_back(lit->first);
		big.push_back(lit->second);
		++lit;
	}
	big.push_back(extra);
	recList(big);




	std::cout << "Small ";
	printList(small);
	std::cout << "Big ";
	printList(big);
};

void PmergeMe::printVec(std::vector<int>& vec) {
	std::vector<int>::const_iterator vit = vec.begin();
	std::vector<int>::const_iterator veit = vec.end();

	std::cout << "Vector:" << std::endl;
		while (vit != veit) {
			std::cout << *vit << std::endl;
			++vit;
		}
};

void PmergeMe::printList(std::list<int>& lst) {
	std::list<int>::const_iterator lit = lst.begin();
	std::list<int>::const_iterator leit = lst.end();
	std::cout << "List:" << std::endl;
		while (lit != leit) {
			std::cout << *lit << std::endl;
			++lit;
		}
};

PmergeMe::PmergeMe(int argc, char **argv) {
	clock_t start, end;
	std::vector<int> vec;
	std::list<int> lst;
	setVec(vec, argc, argv);
	setList(lst, vec);

	printVec(vec);
	printList(lst);

	start = clock();
	orderVec(vec);
	end = clock();
	//printVec(vec);
	std::cout << "time taken to order vector: " << (end - start / CLOCKS_PER_SEC) << "ms" << std::endl;

	start = clock();
	orderList(lst);
	end = clock();
	//printList(lst);
	std::cout << "time taken to order list: " << (end - start / CLOCKS_PER_SEC) << "ms" << std::endl;
};

PmergeMe::~PmergeMe() {
};
