#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <list>
#include <vector>
#include <iostream>

class PmergeMe {
private:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);

	void setVec(std::vector<int>& vec, int argc, char **argv);
	void setList(std::list<int>& lst, const std::vector<int>& vec);
	void printVec(std::vector<int>& vec);
	void printList(std::list<int>& lst);
	void orderVec(std::vector<int>& vec);
	void orderList(std::list<int>& lst);
	void recVec(std::vector<int>& big);
	void recList(std::list<int>& big);
	std::vector<std::pair<int, int> > vecPairs(std::vector<int>& vec, int& extra);
	std::list<std::pair<int, int> > listPairs(std::list<int>& lst, int& extra);
public:
	PmergeMe(int argc, char **argv);
	~PmergeMe();
};

#endif
