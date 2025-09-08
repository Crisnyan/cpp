#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <list>
#include <vector>
#include <ctime>
#include <stdexcept>
#include <limits>
#include <iostream>
#include <cerrno>
#include <cstdlib>

class PmergeMe {
private:
	std::list<int> m_lst;
	std::vector<int> m_vec;

	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);

	void setVec(int argc, char **argv);
	void setList(const std::vector<int>& vec);
public:
	PmergeMe(int argc, char **argv);
	~PmergeMe();
};

#endif
