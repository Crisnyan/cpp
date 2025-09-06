#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <set>

int main() {
	std::vector<int> arr;
	std::list<int> lst;
	std::deque<int> deq;
	std::set<int> set;

	arr.push_back(0);
	arr.push_back(1);
	arr.push_back(2);
	lst.push_back(0);
	lst.push_back(1);
	lst.push_back(2);
	deq.push_back(0);
	deq.push_back(1);
	deq.push_back(2);
	set.insert(0);
	set.insert(1);
	set.insert(2);
	
	try {
		std::vector<int>::const_iterator it;
		it = easyfind(arr, 1);
		std::cout << "val is in pos: " << *it << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::list<int>::const_iterator it;
		it = easyfind(lst, 1);
		std::cout << "val is in pos: " << *it << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}


	try {
		std::deque<int>::const_iterator it;
		it = easyfind(deq, 1);
		std::cout << "val is in pos: " << *it << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}


	try {
		std::set<int>::const_iterator it;
		it = easyfind(set, 1);
		std::cout << "val is in pos: " << *it << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
